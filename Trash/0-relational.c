int foo(void);//returns predicate
char bar(void);//return promotes to predicate
void buh(void);
int main(void){
	void *a;//predicate
	void **b;//predicate
	int c, d;//predicate
	int *e, *f;//predicate
	int **g, **h;//predicate
	char j, k;//promotes to predicate
	char *l, *m;//predicate
	char **n, **o;//predicate
	void *p[10];
	void **q[10];
	int r[10];
	int *s[10];
	int **t[10];
	char u[10];
	char *v[10];
	char **w[10];
