#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000

int read_col_num(int cols[], int max);
void rearrange(char *output, char const *input,
		int n_cols, int const cols[]);
int main(void)
{
	int n_cols; //进行处理的行标号
	int cols[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];
	n_cols = read_col_num(cols, MAX_COLS);
	
	while (gets(input) != NULL){
		printf("Original input:%s\n", input);	
		rearrange(output, input, n_cols, cols);
		printf("Rearrange output:%s\n", output);
	}
	return EXIT_SUCCESS;

}

int read_col_num(int cols[], int max)
{
	int num = 0;
	int ch;

	while (num < max && scanf("%d",&cols[num]) == 1
			&& cols[num] >= 0)
		num += 1;

	//确认已经读取的标号是偶数
	if (num % 2 != 0){
		puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}

	//丢弃该行最后的内容
	while ((ch = getchar()) != EOF && ch != '\n')
		;
	return num;
}

void rearrange(char *output, char const *input,
		int n_cols, int const cols[])
{
	int col; //cols[]数组的下标
	int output_col; //输出列计数器
	int len; //输入行的长度

	len = strlen(input);
	output_col = 0;

	//处理每一对标号
	for (col = 0; col < n_cols; col += 2){
		int nchars = cols[col + 1] - cols[col] + 1;
		//如果输入行结束或者输出行已满，结束
		if (cols[col] >= len || output_col == MAX_INPUT - 1)
			break;
		if (output_col +  nchars > MAX_INPUT -1)
			nchars = MAX_INPUT -output_col - 1;
		//复制数据
		strncpy(output + output_col, input + cols[col], nchars);
		output_col += nchars;
	}
	output[output_col] = '\0';
	
}
