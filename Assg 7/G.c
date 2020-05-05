#include<stdio.h>
#include<string.h>

int val(char ch){
	if (ch == 'M')
		return 1000;
	else if(ch == 'D')
		return 500;
	else if(ch == 'C')
		return 100;
	else if (ch == 'L')
		return 50;
	else if(ch == 'X')
		return 10;
	else if(ch == 'V')
		return 5;
	else
		return 1;
}

int romanToDecimal(char* str) { 
    int res = 0;
    int n = strlen(str);
    for (int i=0; i < n; i++){
    	int s1 = val(str[i]);
        if (i+1 < n){
            int s2 = val(str[i+1]);
            if (s1 >= s2){
                res = res + s1;
            }
            else{
                res = res + s2 - s1;
                i++;
            }
        }
        else{
            res = res + s1;  
        }
    }
    return res; 
}

int main(){
	int n,m;
	scanf("%d", &n);
	char rom[1001];
	for(int i = 0; i < n; i++)
		scanf("%s",rom);
	romanToDecimal(rom);
}