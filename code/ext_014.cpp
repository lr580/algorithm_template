int contains(Polygon g, Point p) //伪代码
{
    int n = g.size();
    bool x = false;
    for(int i=0;i<n;i++)
    {
        Point a = g[i] - p, b = g[(i+1)%n]-p;
        if(abs(cross(a,b))<EPS&&dot(a,b)<EPS)
            return 1;
        if(a.y<b.y) swap(a,b);
        if(a.y<EPS && EPS<b.y && cross(a,b)>EPS)
            x=!x;
    }
    return (x?2:0);
}
