#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <float.h>
#include <pthread.h>
#define MIN(a,b) (((a)<(b)) ? a : b)
#define MAX(a,b) (((a)>(b)) ? a : b)
#define MULTIPLY(a, b) a*b 
#define merge(a, b) a##b 
#define get(a) #a 
#define MKSTR( x ) #x

#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)
#define B(x) S_to_binary_(#x)
unsigned long long S_to_binary_(const char *s)
{
	unsigned long long i = 0;
	while (*s)
	{
		i <<= 1;
		i += *s++ - '0';
	}
	return i;
}

typedef char string;

typedef struct sand
{
    float total;
    int count;
    int tax_percent;
}box;

typedef struct Data
{
	int i; //4 bytes
	__int8_t k; //1 byte
	__int16_t l; //2 byte
	__int32_t m; //4 byte
	__int64_t n; //8 byte
	long int j; //8 byte
	float f; //4 byte
	double g; //8 byte
	long double h; //8 byte
	string str[0]; //1 byte
}infa;

void test()
{
	srand((unsigned)time(NULL));
	int hex = rand() % 0xFFF;
	int dec = rand() % 20;
	int bin = rand() % B(111);
	int oct = rand() % 020;
	int i = 0;
	printf("\nHexadecimal number:0x%02X \n", hex); //hexadecimal output
	printf("Decimal RND number: %d\n", dec);
	printf("Binary RND number: %d\n", bin);
	printf("Octal RND number: %o\n", oct);
	printf("Oct and Hex numbers: %o 0x%02X\n", oct, hex);
	printf("~hex = 0x%02X\n", ~hex);
	printf("bin<<1 = %d\n", bin << 2);
	printf("bin>>1 = %d\n", bin >> 2);
	printf("postfix = %i\n", i++);//i=1
	printf("prefix = %i\n", ++i);
	printf("In C programming All graphic "
		"characters are: \n");
	for (i = 0; i <= 127; ++i)
		if (isgraph(i) != 0)
			printf("%c ", i);
	printf("\n");

	//Fn();
	//free(sizeof(struct numbers));
}

void listFiles()
{
	DIR *dp;
	struct dirent *ep;

	dp = opendir("./");
	if (dp != NULL)
	{
		while (ep = readdir(dp))
			puts(ep->d_name);
		(void)closedir(dp);
	}
	else
		perror("Couldn't open the directory");
}

void pointers(int *p, void *ptr)
{
        box *m = (int*)malloc(sizeof(box)); //structure init
        box num =  { 100.0, 200,100 };// C11 struct init
        printf("The size of the structure box = %d %d\n",sizeof(m),sizeof(num));//sizes
        free(m);
	int  i = 0,a=10;
	float y = 5.5;
	int **z = &p;
	**z = 70;
	printf("p contains address %p\n", p);
	printf("p is pointing to the value %d\n", *p);
	// (int*)ptr - does type casting of void  
	// *((int*)ptr) dereferences the typecasted  
	// void pointer variable. 
	printf("Integer variable is = %d\n", *((int*)ptr));
	// void pointer is now float 
	ptr = &y;
	printf("Float variable is= %.2f\n", *((float*)ptr));
	void(*ls_ptr)();  //pointer to function
	ls_ptr = &listFiles;
	(*ls_ptr)();
        
}

void foo()
{
	static int sa = 10; //example of static variable (it saves its value over each function calling)
	int j = 63, x = 4, i = 0, a = 10;
	a += 5;
	sa += 5;
	printf("a = %d, sa = %d\n", a, sa);
	printf("The address of j is %p\n", &j);
	printf("The value of j is %d\n", j);
        printf("address of function foo() is :%p\n", foo);
	pointers(&j, &x);
}

void file()
{
	//writing to file
	FILE *fp= fopen("test.txt", "w+");
	char buff[255];
	int descriptor = fileno(fp);
	if (fp == NULL)
	{
		fprintf(stderr, "\nError opend file\n");
		fclose(fp);
	}
	else
	{
		fprintf(fp, "This is testing for fprintf...\n");
		fputs("This is testing for fputs...\n", fp);
                printf("The file descriptor is %d\n", descriptor);
		fclose(fp);
	}
	//reading the file
	fp = fopen("test.txt", "r");
	while (fgets(buff, sizeof buff, fp))
	{
		printf("%s\n", buff);
	}
	fclose(fp);
	/*while (!feof(fp))
	{
	fgets(buff, 255, (FILE*)fp);
	//fscanf(fp, "%s", buff);
	printf("%s\n", buff);
	}
	*/
}

void preprocessor()
{
	printf("%s\n", __func__);//print the name of the function
	printf("Minimum of 20 and 30 = %d\n", MIN(20, 30));
	printf("Maximum of 20 and 30 = %d\n", MAX(20, 30));
	printf(MKSTR(HELLO C++));
	printf("\nValue of __LINE__ : %d\n", __LINE__);
	printf("Value of __FILE__ : %s\n", __FILE__);
	printf("\nValue of __DATE__ : %s\n", __DATE__);
	printf("\nValue of __TIME__ : %s\n", __TIME__);
	printf("Multiplication = %d\n", MULTIPLY(20, 30));
	//printf(merge("Hello ", "World\n"));
	printf("%s\n", get(GeeksQuiz));
	//printf("\a"); signal exclamation
}

void memory()
{
	float x = 0.1;
	long int a = 1;
	__int8_t z = 2;
	char b = 'G';
	long double c = 3.14;
	struct Data;
	//-------------------------------printing the variables defined above along with their sizes 
	printf("Size of char %d\n",sizeof(b));
	printf("Size of long int %d\n",sizeof(a));
	printf("Size of long double %d\n", sizeof(c));
	printf("Size of float %d\n", sizeof(x));
	printf("Size of int %d\n", sizeof(z));
	printf("Size of structure %d\n", sizeof(infa));
        printf("Value of INT_MAX %d\n", INT_MAX);
        printf("Value of INT_MIN %d\n", INT_MIN);
        printf("Value of FLT_MAX %f\n", FLT_MAX);
        printf("Value of FLT_MIN %d\n", FLT_MIN);
        
}

clock_t zeit()
{
	time_t t;
	struct tm *tmp;
	char MY_TIME[50];
	time(&t);
	//localtime() uses the time pointed by t , 
	// to fill a tm structure with the  
	// values that represent the  
	// corresponding local time. 
	tmp = localtime(&t);
	// using strftime to display time 
	strftime(MY_TIME, sizeof(MY_TIME), "%x - %I:%M%p", tmp);
	printf("Formatted date & time : %s\n", MY_TIME);
	return vremya();
}

void vremya()
{
	clock_t t;
	t = clock();
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("function took %f seconds to execute \n", time_taken);
}

void sigintHandler(int sig_num)
{
		/* Reset handler to catch SIGINT next time.
		Refer http://en.cppreference.com/w/c/program/signal */
		signal(SIGINT, sigintHandler);
		printf("\n Cannot be terminated using Ctrl+C \n");
		fflush(stdout);
}

void except(int x,int y)
{
	double z = 0.0;
	TRY
	{
		if (y == 0)
	THROW;
	printf("No exception caught \n");
	z = x / y;
	//printf("Z= %d\n", z);
	}
		CATCH
	{
		printf("Division by zero\n");
	}
	ETRY;
}
//------------------------------------------------function pointers
enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

typedef struct
{
    char *name;
    enum response_type type;
}response;

void dump(response r)
{
    printf("Dear %s,\n",r.name);
    printf("Unfortunately, your recent dating partner has been calling us to say that you wouldn't see him.\n");   
}

void second_chance(response r)
{
    printf("Dear %s,\n",r.name);
    printf("Good news: your recent partner has asked us to set up a additional dating. Call us asap.\n");
}

void marriage(response r)
{
    printf("Dear %s,\n",r.name);
    printf("Congratulations! Your recent dating partner has called us with marriage offer.\n");
}

void(*replies[])(response) = {dump, second_chance, marriage}; //an array of pointers to functions in brackets
void func_ptr()
{
    response r[] = 
    {
        {"Mike",DUMP}, {"Louis",SECOND_CHANCE}, {"Matthew",SECOND_CHANCE}, {"William",MARRIAGE}
    };
    int i;
    for(i=0;i<4;i++)
    {
        (replies[r[i].type])(r[i]);
    }
        
}
//-------------------------------------------------Ending

void arguments(int args,...) 
{
    va_list ap;
    va_start(ap,args);
    int i;
    for(i=0;i<args;i++)
        printf("Summ: %i\n",va_arg(ap,int));
    va_end(ap);
}

void pythonScript()
{ 
   char *calledPython="./calledPython.py";  
    char *pythonArgs[]={calledPython,"a","b","c",NULL};
    execvp(calledPython,pythonArgs);//Python script execution
    perror("Python execution");
}

void(*func[])() = {listFiles, file, preprocessor, memory, zeit, vremya, foo, test, func_ptr, pythonScript};

//WORK ON THREADS IS IN PROGRESS
void sandbox()
{
    pthread_t t0;
    pthread_t t1;
    if(pthread_create(&t0,NULL,test,NULL)==-1)
        perror("Unable to create a thread t0\n");
    if(pthread_create(&t1,NULL,foo,NULL)==-1)
        perror("Unable to create a thread t1\n");
    void *result;
    if(pthread_join(t0,&result)==-1)
        perror("Can't join thread t0\n");
    if(pthread_join(t1,&result)==-1)
        perror("Can't join thread t1\n");
}

