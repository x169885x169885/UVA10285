#include<iostream>
using namespace std;

int iTestCase;
char cName[100];
int iWidth;
int iLength;
int iMap[101][101];
int iConnectionLen[101][101];
int iMaxConnection;

int Max (int x, int y)
    {
    if (x>y)
        return x;
    else
        return y;
	}
	
void Update (int x, int y)
    {
	int iDirection[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
		
	if (x<0 || y<0 || x>iWidth || y>iLength)
	    {
	    return;
		}
	
	for (int i=0;i<4;i++)
	    {
	    int iTempX=x+iDirection[i][0];
	    int iTempY=y+iDirection[i][1];
	    
	    if (iMap[iTempX][iTempY]>iMap[x][y])
	        {
	        if (iConnectionLen[iTempX][iTempY]<iConnectionLen[x][y]+1)
	            {
	            iConnectionLen[iTempX][iTempY]=iConnectionLen[x][y]+1;
	            Update(iTempX,iTempY);
				}
			}
		}
	}

int main ()
    {
    int i,j;
    
    
    cin >> iTestCase;
    
    while (iTestCase--)
        {
        cin >> cName >> iWidth >> iLength;
        
        iMaxConnection=0;
        
        for (i=0;i<101;i++)
            {
            for (j=0;j<101;j++)
                {
                iMap[i][j]=200;
                iConnectionLen[i][j]=1;
				}
			}
			
		for (i=1;i<=iWidth;i++)
		    {
		    for (j=1;j<=iLength;j++)
		        cin >> iMap[i][j];
			}
			
		
		for (i=1;i<=iWidth;i++)
		    {
		    for (j=1;j<=iLength;j++)
		        {
				Update(i,j);
				}
			}
			
		for (i=1;i<=iWidth;i++)
		    {
		    for (j=1;j<=iLength;j++)
		        {
		        if (iConnectionLen[i][j]>iMaxConnection)
		            iMaxConnection=iConnectionLen[i][j];
				}
			}
			
		cout << cName << ": " << iMaxConnection << endl;
		}
	}
