while (lf < rf)
{
    ll tri = (rf - lf) / 3;
    ll lc = lf + tri, rc = rf - tri;
    db lv = calc(lc), rv = calc(rc);
    ans = min({ans, lv, rv});
    if (lv < rv)
    {
        rf = rc - 1;
    }
    else
    {
        lf = lc + 1;
    }
}
