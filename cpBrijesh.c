#include <stdio.h>
#include <string.h>
int getnbr(char *str)
{
	int result;
	int puiss;

	result = 0;
	puiss = 1;
	while (('-' == (*str)) || ((*str) == '+'))
	{
		if (*str == '-')
			puiss = puiss * -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		result = (result * 10) + ((*str) - '0');
		str++;
	}
	return (result * puiss);
}


void OctalToDecimal(char str[]) {
    int num = getnbr(str);
	int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 8;
    }
	sprintf(str, "%d", dec_value);
}

void hexadecimalToDecimal(char hexVal[])
{
    int len = strlen(hexVal);
    int base = 1;
    int dec_val = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += ((hexVal[i]) - 48) * base;
            base = base * 16;
        }
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += ((hexVal[i]) - 55) * base;
            base = base * 16;
        }
    }
	sprintf(hexVal, "%d", dec_val);
}

void remove_all_chars(char str[], char c) {
	char *pr = str, *pw = str;
	while (*pr) {
		*pw = *pr++;
		pw += (*pw != c);
	}
	*pw = '\0';
}


char check(char *text)
{
	int j;
	j = strlen(text);
	while(j--)
	{
		if(text[j] >= '0' && text[j] <= '9')
			continue;
		return 0;
	}
	return 1;
}

int chkType(char str[], int base) {
	if (base > 16)
		return 0;
	else if (base <= 10) {
		for (int i = 0; i < strlen(str); i++)
			if (!(str[i] >= '0' && str[i] < ('0' + base)))
				return 0;
	}
	else {
		for (int i = 0; i < strlen(str); i++)
			if (! ((str[i] >= '0' &&
							str[i] < ('0' + base)) ||
						(str[i] >= 'A' &&
						 str[i] < ('A' + base - 10))
				  ))
				return 0;
	}
	return 1;
}
void convert_to_base3(char inp1[],char inp2[]){
	int num = getnbr(inp1);
	int ret = 0, factor = 1;
    while (num > 0) {
        ret += num % 3 * factor;
        num /= 3;
        factor *= 10;
    }
	sprintf(inp2, "%d", ret);
}
void convert_to_base5(char inp1[],char inp2[]){
	int num = getnbr(inp1);
	int ret = 0, factor = 1;
    while (num > 0) {
        ret += num % 5 * factor;
        num /= 5;
        factor *= 10;
    }
	sprintf(inp2, "%d", ret);
}

void convert_to_base7(char inp1[],char inp2[]){
	int num = getnbr(inp1);
	int ret = 0, factor = 1;
    while (num > 0) {
        ret += num % 7 * factor;
        num /= 7;
        factor *= 10;
    }
	sprintf(inp2, "%d", ret);
}

void convert_to_base9(char inp1[],char inp2[]){
	int num = getnbr(inp1);
	int ret = 0, factor = 1;
    while (num > 0) {
        ret += num % 9 * factor;
        num /= 9;
        factor *= 10;
    }
	sprintf(inp2, "%d", ret);
}


void add(char inp1[], char inp2[]){
	int x = getnbr(inp1);
	int y = getnbr(inp2);
	sprintf(inp1, "%d", x+y);
	convert_to_base3(inp1,inp1);
}

void subtract(char inp1[], char inp2[]){
	int x = getnbr(inp1);
	int y = getnbr(inp2);
	sprintf(inp1, "%d", x-y);
	convert_to_base3(inp1,inp1);
}

void multiply1(char inp1[], char inp2[]){
	int x = getnbr(inp1);
	int y = getnbr(inp2);
	sprintf(inp1, "%d", x*y);
	convert_to_base9(inp1,inp1);
}

void divide(char inp1[], char inp2[]){
	int x = getnbr(inp1);
	int y = getnbr(inp2);
	sprintf(inp1, "%d", x/y);
	convert_to_base5(inp1,inp1);
}

void remainder1(char inp1[], char inp2[]){
	int x = getnbr(inp1);
	int y = getnbr(inp2);
	sprintf(inp1, "%d", x%y);
	convert_to_base7(inp1,inp1);
}

void doThings(char str[]){
	char vals[3][50];
	char *found,delim;
	int idx=0,err1=0,err2=0;
	found = strpbrk(str, "+-*/%");
	delim = *found;
	char *ptr = strtok(str, &delim);
	while(ptr != NULL)
	{
		strcpy(vals[idx],ptr);
		idx++;
		ptr = strtok(NULL, &delim);
	}
	remove_all_chars(vals[0],'(');
	remove_all_chars(vals[0],')');
	remove_all_chars(vals[1],'(');
	remove_all_chars(vals[1],')');

	if(!chkType(vals[0],8) && !chkType(vals[0],10) && !chkType(vals[0],16)){
		err1=1;
	}
	if(!chkType(vals[1],8) && !chkType(vals[1],10) && !chkType(vals[1],16)){
		err2=1;
	}

	if(err1 || err2){
		char msg1[2][10],msg2[2][10];
		if(err1 &&  err2){
	//		strcpy(msg1[0],"(error)");
			printf("error1&2");
		}
		else if(err2){
			printf("error2");
		}else if(err2){
			printf("error1");
		}
			return;
	}

	if(vals[0][0]=='0' && vals[0][1]!='x'){
		OctalToDecimal(vals[0]);
	}
	if(vals[1][0]=='0' && vals[1][1]!='x'){
		OctalToDecimal(vals[1]);
	}
	
	if(vals[0][0]=='0' && vals[0][1]=='x'){
		hexadecimalToDecimal(vals[0]);
	}
	if(vals[1][0]=='0' && vals[1][1]=='x'){
		hexadecimalToDecimal(vals[1]);
	}
	
	switch (delim) {
		case '+':
			add(vals[0],vals[1]);
			break;
		case '-':
			subtract(vals[0],vals[1]);
			break;
		case '*':
			multiply1(vals[0],vals[1]);
			break;
		case '/':
			divide(vals[0],vals[1]);
			break;
		case '%':
			remainder1(vals[0],vals[1]);
			break;
	}	
	printf("%s\n",vals[0]);
}

int main()
{
	int ttl=0;
	scanf("%d",&ttl);
	while(ttl--){
		char str[100];
		scanf("%s",str);
		doThings(str);
	}
	return 0;
}

