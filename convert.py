#!/usr/bin/env python3
# -*- coding: utf-8 -*-
r"""
将 lr580/algorithm_template 的 template.md 转换为双栏 LaTeX(ctexart)。
- 代码块：minted 语法高亮 + 行号
- 公式：行内 $...$ / 行间 $$...$$，修复 MathJax 风格的 \matrix，中文自动包 \text
- 目录：\tableofcontents
"""
import re
import sys
import os

# ----------------------------------------------------------------------------
# 数学修复
# ----------------------------------------------------------------------------

def _match_brace(s, open_pos):
    """s[open_pos] == '{'，返回匹配 '}' 的位置，找不到返回 -1。"""
    depth = 0
    i = open_pos
    while i < len(s):
        c = s[i]
        if c == '\\':
            i += 2
            continue
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


def fix_matrix(s):
    """MathJax 的 \\matrix{...} -> \\begin{matrix}...\\end{matrix}"""
    out = []
    i = 0
    while i < len(s):
        m = re.match(r'\\matrix\b', s[i:])
        if m:
            j = i + m.end()
            while j < len(s) and s[j] in ' \t':
                j += 1
            if j < len(s) and s[j] == '{':
                end = _match_brace(s, j)
                if end > 0:
                    inner = s[j + 1:end]
                    out.append(r'\begin{matrix}' + inner + r'\end{matrix}')
                    i = end + 1
                    continue
        out.append(s[i])
        i += 1
    return ''.join(out)


# CJK 汉字 + CJK 标点 + 全角符号
_CJK_RE = re.compile(
    r'[一-鿿　-〿＀-￯]+'
)

def wrap_cjk_math(s):
    """数学模式中出现的连续中文/全角字符用 \\text{} 包裹。"""
    # 先保护已经存在的 \text{...}（平衡花括号）
    protected = []
    def _protect(m):
        end = _match_brace(s, m.end() - 1)
        protected.append(s[m.start():end + 1])
        return '\x01T%d\x01' % (len(protected) - 1)
    s = re.sub(r'\\text\{', _protect, s)
    s = _CJK_RE.sub(lambda m: r'\text{' + m.group() + '}', s)
    for k, v in enumerate(protected):
        s = s.replace('\x01T%d\x01' % k, v)
    return s


# ----------------------------------------------------------------------------
# 行内转换
# ----------------------------------------------------------------------------

def _one_mintinline(code):
    """生成单个不可断行的 \\mintinline。"""
    for d in r'|!?@:"~^*+;,./0123456789<>-':
        if d not in code:
            return r'\mintinline{text}' + d + code + d
    return r'\mintinline{text}{' + code.replace('}', r'\}') + '}'


def _math_allow_break(s):
    """长行内公式在环境外的逗号后允许断行。"""
    boxes = []

    def _stash(m):
        boxes.append(m.group(0))
        return '\x02%d\x02' % (len(boxes) - 1)
    s2 = re.sub(r'\\begin\{[^}]+\}.*?\\end\{[^}]+\}', _stash, s, flags=re.S)
    s2 = s2.replace(',', r',\allowbreak{}')
    for k, v in enumerate(boxes):
        s2 = s2.replace('\x02%d\x02' % k, v)
    return s2


def _mint_inline(code):
    """长行内代码（逗号分隔的列表）在逗号后允许断行。"""
    if len(code) > 30 and ',' in code:
        parts = code.split(',')
        out = [_one_mintinline(parts[0])]
        for p in parts[1:]:
            out.append(',\\allowbreak ' + _one_mintinline(p))
        return ''.join(out)
    return _one_mintinline(code)


def _escape_text(s):
    s = s.replace('\\', r'\textbackslash{}')
    s = s.replace('&', r'\&')
    s = s.replace('%', r'\%')
    s = s.replace('$', r'\$')
    s = s.replace('#', r'\#')
    s = s.replace('_', r'\_')
    s = s.replace('{', r'\{')
    s = s.replace('}', r'\}')
    s = s.replace('~', r'\textasciitilde{}')
    s = s.replace('^', r'\textasciicircum{}')
    return s


def inline(s):
    """行内 markdown -> LaTeX。"""
    stash = []

    def put(latex):
        stash.append(latex)
        return '\x00%d\x00' % (len(stash) - 1)

    # 0. 圈数字 ①②③ -> \ding{192..194}
    for _i, _ch in enumerate('①②③④⑤⑥⑦⑧⑨', start=1):
        s = s.replace(_ch, put(r'\cds{%d}' % _i))

    # 1. 行内代码（双反引号优先，再单反引号）
    def _code(m):
        return put(_mint_inline(m.group(1)))
    s = re.sub(r'``([^`]+)``', _code, s)
    s = re.sub(r'`([^`]+)`', _code, s)

    # 2. 链接 / 图片
    def _link(m):
        whole = m.group(0)
        text = m.group(1)
        url = m.group(2)
        if whole.startswith('!'):
            url_e = url.replace('%', r'\%').replace('#', r'\#')
            return put(r'\includegraphics[width=0.9\linewidth]{' + url_e + '}')
        url_e = url.replace('%', r'\%').replace('#', r'\#').replace('&', r'\&')
        return put(r'\href{' + url_e + '}{' + inline(text) + '}')
    s = re.sub(r'!?\[([^\]]*)\]\(([^)\s]+)\)', _link, s)

    # 3. 行内公式（此时行内代码已被占位，不会误匹配 `$`）
    def _imath(m):
        body = _fix_subscript_op(wrap_cjk_math(fix_matrix(m.group(1))))
        if len(body) > 30:
            body = _math_allow_break(body)
        return put('$' + body + '$')
    s = re.sub(r'\$([^$\n]+?)\$', _imath, s)

    # 4. 粗体（内容里的纯文本需转义，占位符不受影响）
    def _bold(m):
        inner = _escape_text(m.group(1))
        return put(r'\textbf{' + inner + '}')
    s = re.sub(r'\*\*([^*]+)\*\*', _bold, s)

    # 5. 纯文本转义
    s = _escape_text(s)

    # 6. 恢复占位符（循环到全部恢复，兼容嵌套占位符）
    while '\x00' in s:
        m = re.search(r'\x00(\d+)\x00', s)
        if not m:
            break
        k = int(m.group(1))
        s = s[:m.start()] + stash[k] + s[m.end():]
    return s


# ----------------------------------------------------------------------------
# 块级元素
# ----------------------------------------------------------------------------

def _indent(line):
    n = 0
    for c in line:
        if c == ' ':
            n += 1
        elif c == '\t':
            n += 4
        else:
            break
    return n


# ----------------------------------------------------------------------------
# 代码块外部化
#   - 与仓库 code/ 中文件规范化内容一致的块  -> 引用 code/xxx
#   - 行数超过 INLINE_MAX_LINES 的其余块      -> 抽取为 code/ext_NNN.* 新文件
#   - 行数不超过阈值的小段                    -> 直接内嵌 minted 环境
# ----------------------------------------------------------------------------

CODE_MAP = {}          # 规范化内容 -> code 相对路径（如 code/xxx.cpp）
NEW_CODE_DIR = None    # 新外置代码文件写入目录（code/ 绝对路径）
NEW_CODE_REL = 'code'
NEW_PREFIX = 'ext_'    # 新建文件统一前缀，与原仓库文件区分
INLINE_MAX_LINES = 10  # 代码块行数超过该值即外置到 code/
_CODE_EXT = {'cpp': 'cpp', 'c': 'c', 'java': 'java', 'python': 'py'}
_new_counter = 0


def _canonical_code(code):
    """规范化一份代码：去首尾空行、tab 展开为 2 空格、行尾空白去除。

    用于与 code/ 文件做内容比对（minted 的 tabsize=2 与 expandtabs(2) 等价）。
    """
    lines = list(code)
    while lines and lines[-1].strip() == '':
        lines.pop()
    while lines and lines[0].strip() == '':
        lines.pop(0)
    lines = [l.expandtabs(2).rstrip() for l in lines]
    return '\n'.join(lines)


def build_code_map(code_dir):
    """扫描 code/ 目录，建立 规范化内容 -> 相对路径 映射。"""
    CODE_MAP.clear()
    if not code_dir or not os.path.isdir(code_dir):
        return
    for root, _, files in os.walk(code_dir):
        for fn in files:
            ap = os.path.join(root, fn)
            rel = os.path.relpath(ap, os.path.dirname(code_dir.rstrip(os.sep))).replace(os.sep, '/')
            try:
                with open(ap, encoding='utf-8') as f:
                    content = f.read()
            except (UnicodeDecodeError, OSError):
                continue
            key = _canonical_code(content.split('\n'))
            CODE_MAP.setdefault(key, rel)


def _render_code(lang, code):
    global _new_counter
    table = {'c++': 'cpp', 'c': 'c', 'java': 'java', 'python': 'python',
             'cpp': 'cpp', 'py': 'python'}
    lexer = table.get(lang.lower().strip(), 'text')
    # 规范化：去首尾空行、tab 展开为 2 空格（与内嵌渲染一致）
    norm = list(code)
    while norm and norm[-1].strip() == '':
        norm.pop()
    while norm and norm[0].strip() == '':
        norm.pop(0)
    norm = [l.expandtabs(2) for l in norm]
    body = '\n'.join(norm)

    # 1) 与仓库 code/ 中内容一致的块：直接引用原文件
    key = _canonical_code(code)
    if key in CODE_MAP:
        return '\\inputminted{%s}{%s}' % (lexer, CODE_MAP[key])

    # 2) 行数超过阈值的大段代码：抽取为 code/ext_NNN.* 新文件并引用
    if len(norm) > INLINE_MAX_LINES:
        ext = _CODE_EXT.get(lexer, 'txt')
        _new_counter += 1
        name = '%s%03d.%s' % (NEW_PREFIX, _new_counter, ext)
        if NEW_CODE_DIR:
            os.makedirs(NEW_CODE_DIR, exist_ok=True)
            with open(os.path.join(NEW_CODE_DIR, name), 'w', encoding='utf-8') as f:
                f.write(body + '\n')
        return '\\inputminted{%s}{%s/%s}' % (lexer, NEW_CODE_REL, name)

    # 3) 小段代码：直接内嵌
    return '\\begin{minted}{%s}\n%s\n\\end{minted}' % (lexer, body)


_MATH_OPS = ('min|max|gcd|lcm|lim|inf|sup|arg|det|exp|dim|deg|Pr|log|ln|lg|'
             'sin|cos|tan|cot|sec|csc|sinh|cosh|tanh|arcsin|arccos|arctan')
_SUB_OP_RE = re.compile(r'([_^])\\(' + _MATH_OPS + r')\b')


def _fix_subscript_op(s):
    """x_\\min -> x_{\\min}（operator 类 token 做下标需加花括号）。"""
    return _SUB_OP_RE.sub(r'\1{\\\2}', s)


# 自带数学模式的顶层环境
_TOP_MATH_ENVS = ('align', 'gather', 'equation', 'multline', 'alignat',
                  'flalign', 'displaymath')


def _wrap_fit(math_inner):
    """把数学内容包进 adjustbox：超宽则缩至栏宽，否则原样居中。"""
    return (r'\begin{adjustbox}{max width=\linewidth,center}' + '\n$' +
            math_inner + r'$' + '\n' + r'\end{adjustbox}')


def _render_display(block):
    s = block.strip()
    # 数学块内不允许空行（\par），统一删除
    s = '\n'.join(l for l in s.split('\n') if l.strip())
    s = _fix_subscript_op(wrap_cjk_math(fix_matrix(s)))
    # 整个块是否为完整的一个顶层数学环境（begin/end 同名）
    whole = re.match(r'^\\begin\{([a-zA-Z]+)\*?\}(.*)\\end\{\1\}\*?\s*$',
                     s, re.S)
    if whole and whole.group(1) in _TOP_MATH_ENVS:
        env = whole.group(1)
        inner = whole.group(2)
        if env in ('align', 'alignat', 'flalign', 'multline'):
            return _wrap_fit(r'\begin{aligned}' + inner + r'\end{aligned}')
        if env == 'gather':
            return _wrap_fit(r'\begin{gathered}' + inner + r'\end{gathered}')
        # equation / displaymath：内部即普通公式
        return _wrap_fit(inner)
    # 去掉所有显式环境，仅检查顶层是否有换行/对齐
    env_stripped = re.sub(r'\\begin\{[^}]+\}.*?\\end\{[^}]+\}', '', s,
                          flags=re.S)
    has_cr = r'\\' in env_stripped
    if has_cr:
        if '&' in env_stripped:
            return _wrap_fit(r'\begin{aligned}' + '\n' + s +
                             '\n' + r'\end{aligned}')
        return _wrap_fit(r'\begin{gathered}' + '\n' + s +
                         '\n' + r'\end{gathered}')
    # 单行公式
    return _wrap_fit(s)


def _render_table(rows):
    def _split(r):
        r = r.strip()
        if r.startswith('|'):
            r = r[1:]
        if r.endswith('|'):
            r = r[:-1]
        return [c.strip() for c in r.split('|')]

    header = _split(rows[0])
    sep = _split(rows[1])
    aligns = []
    for c in sep:
        l = c.startswith(':')
        r = c.endswith(':')
        aligns.append('c' if l and r else ('l' if l else ('r' if r else 'c')))
    data = [_split(x) for x in rows[2:]]
    ncol = len(header)
    aligns = (aligns + ['c'] * ncol)[:ncol]

    out = ['\\begin{table*}[t]', '\\centering', '\\small',
           '\\begin{tabular}{' + ''.join(aligns) + '}', '\\toprule',
           ' & '.join(inline(c) for c in header) + r' \\',
           r'\midrule']
    for row in data:
        row = (row + [''] * ncol)[:ncol]
        out.append(' & '.join(inline(c) for c in row) + r' \\')
    out += [r'\bottomrule', r'\end{tabular}', r'\end{table*}']
    return '\n'.join(out)


def _marker(line, indent):
    if _indent(line) != indent:
        return None
    m = re.match(r'^' + ' ' * indent + r'(?:([-*])|(\d+)\.)\s+', line)
    if not m:
        m = re.match(r'^' + ' ' * indent + r'(?:([-*])|(\d+)\.)\s*$', line)
    return m


def _parse_list(lines, start, indent):
    """从 start 解析 marker 缩进为 indent 的列表，返回 (latex, next_idx)。"""
    n = len(lines)
    items = []
    i = start
    while i < n:
        m = _marker(lines[i], indent)
        if not m:
            break
        ordered = m.group(2) is not None
        content_col = m.end()
        content = [lines[i][content_col:]]
        i += 1
        while i < n:
            l2 = lines[i]
            if l2.strip() == '':
                j = i + 1
                while j < n and lines[j].strip() == '':
                    j += 1
                if j < n:
                    jind = _indent(lines[j])
                    if jind > indent or (jind == indent and
                                        not _marker(lines[j], indent)):
                        content.append('')
                        i += 1
                        continue
                break
            ind2 = _indent(l2)
            if ind2 == indent and _marker(l2, indent):
                break
            if ind2 < indent:
                break
            if ind2 >= content_col:
                content.append(l2[content_col:])
            else:
                stripped = l2.lstrip()
                # 缩进不足且是新块级元素开始（围栏/标题/表格/公式/引用），
                # 说明列表已结束，不能吞进列表项（否则会丢失代码缩进）
                if (re.match(r'^```', stripped)
                        or re.match(r'^#{1,6}\s', stripped)
                        or re.match(r'^\|', stripped)
                        or re.match(r'^\$\$', stripped)
                        or re.match(r'^>', stripped)):
                    break
                content.append(stripped)  # lazy continuation
            i += 1
        items.append((ordered, content))

    rendered = []
    k = 0
    while k < len(items):
        ordered = items[k][0]
        env = 'enumerate' if ordered else 'itemize'
        block = ['\\begin{%s}' % env]
        while k < len(items) and items[k][0] == ordered:
            inner = parse_blocks(items[k][1]).strip()
            block.append('\\item ' + inner)
            k += 1
        block.append('\\end{%s}' % env)
        rendered.append('\n'.join(block))
    return '\n'.join(rendered), i


def parse_blocks(lines):
    """把一组 markdown 行转换为 LaTeX。"""
    out = []
    i = 0
    n = len(lines)
    while i < n:
        line = lines[i]
        if line.strip() == '':
            i += 1
            continue

        # 标题
        m = re.match(r'^(#{1,6})\s+(.*)$', line)
        if m:
            level = len(m.group(1))
            cmds = {2: r'\section', 3: r'\subsection',
                    4: r'\subsubsection', 5: r'\hfive', 6: r'\hsix'}
            if level == 1:
                out.append('%% [文档标题] ' + m.group(2))
            else:
                out.append(cmds[level] + '{' + inline(m.group(2)) + '}')
            i += 1
            continue

        # 围栏代码
        m = re.match(r'^```\s*([\w+#]*)\s*$', line)
        if m:
            lang = m.group(1) or 'text'
            code = []
            i += 1
            while i < n and not re.match(r'^```\s*$', lines[i]):
                code.append(lines[i])
                i += 1
            i += 1  # 结束围栏
            out.append(_render_code(lang, code))
            continue

        # 行间公式
        m = re.match(r'^\s*\$\$(.*?)\$\$\s*$', line)
        if m:
            out.append(_render_display(m.group(1)))
            i += 1
            continue
        if re.match(r'^\s*\$\$', line):
            parts = [line.strip()[2:]]
            if not parts[0]:
                parts = []
            i += 1
            while i < n:
                if '$$' in lines[i]:
                    before = lines[i].split('$$', 1)[0]
                    if before.strip():
                        parts.append(before)
                    i += 1
                    break
                parts.append(lines[i])
                i += 1
            out.append(_render_display('\n'.join(parts)))
            continue

        # 引用块
        if re.match(r'^>', line):
            raw = []
            while i < n:
                l = lines[i]
                if l.startswith('> '):
                    raw.append(l[2:])
                    i += 1
                elif l.rstrip() == '>':
                    raw.append('')
                    i += 1
                elif l.startswith('>'):
                    raw.append(l[1:])
                    i += 1
                elif l.strip() == '':
                    j = i + 1
                    while j < n and lines[j].strip() == '':
                        j += 1
                    if j < n and re.match(r'^>', lines[j]):
                        raw.append('')
                        i += 1
                    else:
                        break
                else:
                    break
            inner = parse_blocks(raw)
            out.append('\\begin{notebox}\n' + inner + '\n\\end{notebox}')
            continue

        # 表格
        if re.match(r'^\s*\|', line):
            rows = []
            while i < n and re.match(r'^\s*\|', lines[i]):
                rows.append(lines[i])
                i += 1
            out.append(_render_table(rows))
            continue

        # 列表
        m = re.match(r'^(\s*)(?:[-*]|\d+\.)\s+', line)
        if m:
            latex, ni = _parse_list(lines, i, _indent(line))
            out.append(latex)
            i = ni
            continue

        # 普通段落
        para = []
        while i < n:
            l = lines[i]
            if l.strip() == '':
                break
            if (re.match(r'^(#{1,6})\s+', l) or re.match(r'^```', l) or
                    re.match(r'^>', l) or re.match(r'^\s*\$\$', l) or
                    re.match(r'^\s*\|', l)):
                break
            mm = re.match(r'^(\s*)(?:[-*]|\d+\.)\s+', l)
            if mm and _indent(l) == 0:
                break
            para.append(l.strip())
            i += 1
        if para:
            out.append(inline(' '.join(para)))

    return '\n\n'.join(x for x in out if x.strip())


# ----------------------------------------------------------------------------
# LaTeX 文档框架
# ----------------------------------------------------------------------------

PREAMBLE = r"""% ============================================================================
% LaTeX 版构建说明
% ----------------------------------------------------------------------------
% 本文件由 template.md 经 convert.py 自动转换生成，请勿手动编辑正文部分。
%
% 【成品】
%   algorithm_template.tex —— 本 LaTeX 源文件
%   algorithm_template.pdf —— 已编译成品（130 页，XeLaTeX）
%
% 【代码来源】正文 286 个代码块分三类处理：
%   130 个 —— 与仓库 code/ 中原有文件内容逐字一致，以 \inputminted 引用 code/xxx；
%   83  个 —— 代码行数超过 10 行、但 code/ 中没有对应文件，
%             由转换器抽取为新文件 code/ext_NNN.*（统一前缀 ext_，
%             沿用原仓库的小写下划线 snake_case 命名），同样以 \inputminted 引用；
%   73  个 —— 不超过 10 行的小段代码，直接以 minted 环境内嵌在本文件中。
%   所有代码内容与 template.md 完全一致（已逐块程序化校验）。
%
% 【重新生成】
%   python3 convert.py template.md algorithm_template.tex
%   运行后自动：扫描 code/ 建立内容匹配，一致的块写为 \inputminted 引用；
%   超过 10 行的其余块写入 code/ext_NNN.*（每次运行先清理旧的 ext_*，
%   保证幂等、编号连续）；不超过 10 行的小段直接内嵌为 minted 环境。
%
% 【重新编译】
%   依赖：TeX Live 2022（或更新版本，需含 ctexart、minted、tcolorbox 等），
%         并已安装 Python（minted 语法高亮依赖 Pygments）。
%     xelatex -shell-escape -interaction=nonstopmode algorithm_template.tex
%     xelatex -shell-escape -interaction=nonstopmode algorithm_template.tex
%   必须编译两次：第一遍生成目录，第二遍填充页码。
%   -shell-escape 是 minted 调用 Pygments 所必需。
%
% 【排版特性】
%   引擎：XeLaTeX，ctexart 双栏（twocolumn，10pt）
%   目录：单栏独立排版（封面 + 目录在正文双栏之前）
%   代码：minted 语法高亮（friendly 配色）+ 行号 + 左侧框线，
%         长行自动断行，长代码可跨栏连续且行号连续
%   数学：amsmath / amssymb / esint / mathtools，兼容原 Markdown 的 MathJax 写法
%   表格：宽表 table* 跨双栏 + booktabs
% ============================================================================
\documentclass[twocolumn,10pt]{ctexart}

% ---------- 页面 ----------
\usepackage[a4paper,left=1.5cm,right=1.5cm,top=2.0cm,bottom=2.0cm,
            columnsep=0.6cm]{geometry}
\usepackage{setspace}

% ---------- 数学 ----------
\usepackage{amsmath}
\usepackage{amssymb}
\usepackage{esint}
\usepackage{mathtools}
\allowdisplaybreaks[2]

% ---------- 代码高亮 ----------
\usepackage{xcolor}
\usepackage{minted}
\setmonofont{DejaVu Sans Mono}[Scale=0.85]
\setCJKmonofont{Noto Sans Mono CJK SC}
\setminted{
  linenos,
  numbersep=4pt,
  fontsize=\scriptsize,
  breaklines,
  breaksymbolleft={},
  breakanywhere,
  breakanywheresymbolpre={},
  breakanywheresymbolpost={},
  frame=leftline,
  framerule=0.8pt,
  framesep=5pt,
  tabsize=2,
  baselinestretch=1.0,
  numberblanklines=true,
  resetmargins=true
}
\usemintedstyle{friendly}

% ---------- 引用块（浅色底+左竖线，可跨页/跨栏，可在列表中嵌套） ----------
\usepackage[most]{tcolorbox}
\newtcolorbox{notebox}{
  colback=gray!6, colframe=gray!50,
  boxrule=0pt, leftrule=2pt, arc=0pt, outer arc=0pt,
  left=6pt, right=4pt, top=3pt, bottom=3pt,
  breakable, before skip=8pt, after skip=8pt
}

% ---------- 表格 ----------
\usepackage{booktabs}
\usepackage{pifont}
\newcommand{\cds}[1]{\ding{\numexpr191+#1\relax}}

% ---------- 公式自适应缩放（超宽单行公式缩至栏宽） ----------
\usepackage{adjustbox}

% ---------- 列表 ----------
\usepackage{enumitem}
\setlist{nosep,leftmargin=1.5em,itemsep=1.5pt,topsep=4pt,parsep=0pt}

% ---------- 超链接 ----------
\usepackage[colorlinks=true,linkcolor=blue!60!black,
            urlcolor=blue!60!black,citecolor=blue!60!black]{hyperref}

% ---------- 页眉页脚 ----------
\usepackage{fancyhdr}
\pagestyle{fancy}
\fancyhf{}
\fancyhead[L]{\small lr580's 算法模板}
\fancyhead[R]{\small \nouppercase{\leftmark}}
\fancyfoot[C]{\thepage}
\renewcommand{\headrulewidth}{0.4pt}
\fancypagestyle{plain}{\fancyhf{}\fancyfoot[C]{\thepage}
  \renewcommand{\headrulewidth}{0pt}}

% ---------- 编号 / 目录深度 ----------
\setcounter{secnumdepth}{3}
\setcounter{tocdepth}{3}

% ---------- 5、6 级标题（加粗独立行） ----------
\makeatletter
\newcommand{\hfive}[1]{\par\addvspace{6pt}\@afterindentfalse
  {\noindent\bfseries\normalsize #1}\par\nobreak\vspace{2pt}}
\newcommand{\hsix}[1]{\par\addvspace{4pt}\@afterindentfalse
  {\noindent\bfseries\small #1}\par\nobreak\vspace{1pt}}
\makeatother

% ---------- MathJax 兼容宏 ----------
\newcommand{\Omicron}{O}
\newcommand{\Z}{\mathbb{Z}}
\newcommand{\R}{\mathbb{R}}
\newcommand{\N}{\mathbb{N}}
\newcommand{\ang}{\angle}
\newcommand{\exist}{\exists}
"""

TITLEPAGE = r"""\begin{titlepage}
\centering
\vspace*{2.2cm}
\includegraphics[width=0.38\textwidth]{img/image-20220325120131181.png}\\[1.6cm]
{\Huge\bfseries lr580's 算法模板\par}
\vspace{0.8cm}
{\LARGE Algorithm Template\par}
\vspace{2.2cm}
{\large Version 1.2.3\par}
\vspace{0.4cm}
{\large 最后更新：2025/3/5\par}
\vspace{3.2cm}
{\large \today\par}
\end{titlepage}

\onecolumn
\tableofcontents
\clearpage
\twocolumn
"""


def main():
    src = sys.argv[1] if len(sys.argv) > 1 else 'template.md'
    dst = sys.argv[2] if len(sys.argv) > 2 else 'algorithm_template.tex'
    with open(src, encoding='utf-8') as f:
        text = f.read()

    # 删除零宽字符（U+200B/200C/200D/FEFF）
    for _z in ('​', '‌', '‍', '﻿'):
        text = text.replace(_z, '')

    # 代码外部化：
    #   code/ 中内容一致的块直接引用；超过阈值的大段代码抽取为 code/ext_NNN.*
    #   （先清理上一次生成的 ext_* 文件，保证幂等、编号连续）
    src_dir = os.path.dirname(os.path.abspath(src))
    code_dir = os.path.join(src_dir, 'code')
    global NEW_CODE_DIR
    NEW_CODE_DIR = code_dir
    if os.path.isdir(code_dir):
        for old in os.listdir(code_dir):
            if old.startswith(NEW_PREFIX):
                os.remove(os.path.join(code_dir, old))
    build_code_map(code_dir)

    # 去掉文档开头的 HTML 头部（第一个一级标题之前的内容）
    m = re.search(r'^# ', text, flags=re.M)
    if m:
        text = text[m.start():]

    lines = text.split('\n')
    body = parse_blocks(lines)
    n_input = body.count('\\inputminted')
    n_ext = len(re.findall(r'\\inputminted\{[^}]*\}\{%s/(%s)' % (NEW_CODE_REL, NEW_PREFIX), body))
    n_orig = n_input - n_ext
    n_minted = body.count('\\begin{minted}')

    with open(dst, 'w', encoding='utf-8') as f:
        f.write(PREAMBLE)
        f.write('\n\\begin{document}\n\n')
        f.write(TITLEPAGE)
        f.write('\n')
        f.write(body)
        f.write('\n\\end{document}\n')
    print('written:', dst)
    print('引用原 code 文件: %d 块；新建 %s 外置: %d 块；小段内嵌: %d 块'
          % (n_orig, NEW_PREFIX, n_ext, n_minted))


if __name__ == '__main__':
    main()
