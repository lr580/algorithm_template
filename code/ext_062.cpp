void FFT_match(char *s1,char *s2,int m,int n)
{
  reverse(ss1,ss1+m);
  for(int i=0;i<m;i++) A[i]=(s1[i]!='*')?(s1[i]-'a'+1):0;
  for(int i=0;i<n;i++) B[i]=(s2[i]!='*')?(s2[i]-'a'+1):0;
  
  for(int i=0;i<len;i++) a[i]=Comp(A[i]*A[i]*A[i],0),b[i]=Comp(B[i],0);
  FFT(a,len,1);FFT(b,len,1);
  for(int i=0;i<len;i++) P[i]=P[i]+a[i]*b[i];
  
  for(int i=0;i<len;i++) a[i]=Comp(A[i],0),b[i]=Comp(B[i]*B[i]*B[i],0);
  FFT(a,len,1);FFT(b,len,1);
  for(int i=0;i<len;i++) P[i]=P[i]+a[i]*b[i];
  
  for(int i=0;i<len;i++) a[i]=Comp(A[i]*A[i],0),b[i]=Comp(B[i]*B[i],0);
  FFT(a,len,1);FFT(b,len,1);
  for(int i=0;i<len;i++) P[i]=P[i]-a[i]*b[i]*Comp(2,0);
  
  FFT(P,len,-1);
  for(int i=m-1;i<n;i++) if(fabs(P[i].r)<=1e-7) printf("%d ",i-m+2);
}
