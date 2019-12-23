#include<stdio.h>
#include<stdlib.h>

int strLen(const char* s) {
	int res = 0;
	while(*s++) {
		res++;
	}
	return res;
}

char* strDup(char* s) {
	int len = strLen(s);
	char* res = new char[len + 1];
	char* t = res;
	while( (*t++ = *s++) );
	*t = '\0';
	return res;
}

char* strCpy(const char* s,char* c) {
	while( (*c++ = *s++) );
	*c = '\0';
	return c;
}

char* strCat(char* l, char* r, char separator) {
	int lenL = strLen(l);
	char* res = new char[lenL + strLen(r) + 1];
	res = strDup(l);
	char* t = res + lenL;
	*t++ = separator;
	while( (*t++ = *r++) );
	*t = '\0';
	return res;
}

int strCmp(char* l, char* r) {

	int res = strLen(l) - strLen(r);
	if(res) {
		return res < 0 ? -1 : 1;
	}
	int i = 0;
	while(l[i] == r[i]) {
		if (l[i] == '\0' && r[i] == '\0') break;
		i++;
	}
	res = l[i] - r[i];
	return res < 0 ? -1 : res == 0 ? 0 : 1;
}

void testStrLen() {
	int res = strLen("Hello");
	printf("Len of %s is %d\n", "Hello", res);
}

void testStrDup() {
	char* orig = "Hello";
	char* dupl = strDup(orig);
	printf("Duplicate = %s\n", dupl);
}

void testStrCat() {
	char* s1 = "hello";
	char* s2 = "world";
	char* s3 = strCat(s1, s2, '_');
	printf("%s + %s = %s\n", s1, s2, s3);
}

void testStrCmp() {
	char* s1 = "hello!";
	char* s2 = "hello";
	printf("compare %s with %s result is %d\n", s1, s2, strCmp(s1, s2));
}

int main(void) {
	testStrLen();
	testStrDup();
	testStrCat();
	testStrCmp();
}