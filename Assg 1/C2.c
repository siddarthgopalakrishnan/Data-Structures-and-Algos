#include<stdio.h>
#include<string.h>

int check(int tcount[], int wcount[]){
    int flag = 1;
    for(int i = 0; i<256; i++){
        if(tcount[i] < wcount[i]){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
	char text[1000000], word[1000000];
	scanf("%[^\n]%*c", text);
	scanf("%s", word);
	int tcount[256] = {0}, wcount[256] = {0};
	int wlen=strlen(word);
	int tlen=strlen(text);
	for(int i=0; i<wlen; i++){
        wcount[word[i]]++;
	}
    for(int i = 0; i<wlen; i++){
        if(wcount[text[i]] > 0){
            tcount[text[i]]++;
        }
    }
	int start=0, end=wlen-1;
	int fstart=0, fend=tlen-1;
	while(end<tlen){
        if(check(tcount, wcount)){
            if(fend-fstart>end-start){
                fend=end;
                fstart=start;
            }
        }
        end++;
        int next=text[end];
        int first = text[start];
        if(wcount[next] > 0){
            tcount[next]++;
        }
        while((tcount[first] > wcount[first] || (tcount[first] == 0  && wcount[first] == 0))&& start < end){
            if(wcount[first] > 0){
                tcount[first]--;
            }
            start++;
            first = text[start];
        }
	}
	printf("%d %d\n", fstart, fend);
	for(int i = fstart; i<=fend; i++)
        printf("%c", text[i]);
	return 0;
}