#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
int start=0;
int longestUniqueSubsttr(char* str) 
{ 
	int n = strlen(str);
	int cur_len = 1; // length of current substring 
	int max_len = 1; // result 
	int prev_index; // previous index 
	int i; 
	int* visited = (int*)malloc(sizeof(int)*256); 
	for (i = 0; i < 256; i++) 
		visited[i] = -1; 
	visited[str[0]] = 0; 

	for (i = 1; i < n; i++) { 
		prev_index = visited[str[i]]; 

		/* If the current character is not present in the 
		already processed substring or it is not part of 
		the current NRCS, then do cur_len++ */
		if (prev_index == -1 || i - cur_len > prev_index) 
			cur_len++; 

		/* If the current character is present in currently 
		considered NRCS, then update NRCS to start from 
		the next character of the previous instance. */
		else { 
			/* Also, when we are changing the NRCS, we 
			should also check whether the length of the 
			previous NRCS was greater than max_len or 
			not.*/
			if (cur_len > max_len){
				max_len = cur_len;
				start = prev_index; 
			}

			cur_len = i - prev_index;
		} 

		// update the index of current character 
		visited[str[i]] = i; 
	} 

	// Compare the length of last NRCS with max_len and 
	// update max_len if needed 
	if (cur_len > max_len) 
		max_len = cur_len; 

	free(visited); // free memory allocated for visited 
	return max_len; 
}
int main() 
{ 
	char text[1000000];
	scanf("%[^\n]%*c", text);
	printf("The input string is %s\n", text); 
	int len = longestUniqueSubsttr(text); 
	printf("The length: %d\n", len);
	for(int i = start; i<=(start+len-1); i++){
		printf("%c", text[i]);
	}
	printf("\n");
	return 0; 
}