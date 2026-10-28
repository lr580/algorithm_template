bool check(Point A,Point*p,int n )//判断点在凸包内模板 O（logn）
{
    int l=1,r=n-2,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        double a1=Cross(p[mid]-p[0],A-p[0]);
        double a2=Cross(p[mid+1]-p[0],A-p[0]);
        if(a1>=0&&a2<=0)
        {
            if(Cross(p[mid+1]-p[mid],A-p[mid])>=0)return true;
            return false;
        }
        else if(a1<0)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return false;
}
