#include <stdio.h>
#include <string.h>

int comparator_asc(const void *p, const void *q)
{
    int l = *(const char *)p ;
    int r = *(const char *)q ;

    return l-r ;
}

int comparator_des(const void *p, const void *q)
{
    int l = *(const char *)p ;
    int r = *(const char *)q ;

    return r-l ;
}

void subtract(char str[], char str2[], int len, int ans[])
{
	int i ;
	for(i=len-1; i>=0; i--)
	{
		if(str[i] >= str2[i])
			ans[i] = str[i] - str2[i] ;
		else
		{
			ans[i] = 10 + str[i] - str2[i] ;
			int temp = i ;
			while(str[temp-1] == 0)
			{
				temp-- ;
				str[temp] = '9' ;
			}
			str[temp-1]-- ;	
		}
	}
	
}

int main()
{
	int i ;
    char str[10000] ;
    scanf("%s", str) ;
    char str2[10000] ;
    strcpy(str2, str) ;

    int len = strlen(str) ;
    qsort((void*)str, len, sizeof(str[0]), comparator_des) ;
    qsort((void*)str2, len, sizeof(str[0]), comparator_asc) ;

    if(str2[0] == '0')
    {
        int i=1 ;
        while(str2[i] == '0')
            i++ ;
            
        char c = str2[i] ;
        str2[0] = c ;
        str2[i] = '0' ;
    }
    
    int ans[len] ;
    subtract(str, str2, len, ans) ;
    
    for(i=0; i<len; i++)
    printf("%d", ans[i]) ;
    
}