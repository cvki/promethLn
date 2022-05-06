#pragma warning(disable:4996)//scanf报错忽略
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>




/***给定两个整型数组，本题要求找出不是两者共有的元素。
输入格式:
输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。
输出格式:
在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。题目保证至少存在一个这样的数字。同一数字不重复输出。
输入样例:
10 3 -5 2 8 0 3 5 -15 9 100
11 6 4 8 2 6 -5 9 0 100 8 1
结尾无空行
输出样例:
3 5 -15 6 4 1
结尾无空行******/

//法一，高效率：先排序后查找，有bug
typedef struct arrNum {
    int num[40];
    int sign[40];
}arrNum;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1]) {
                int tem = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tem;
            }
}

int putNum(arrNum* an, int val, int index) {
    if (index == 0) {
        (*an).num[index] = val;
        an->sign[index] = 1;
        return 1;
    }
    else {
        if (an->num[index - 1] == val) {
            an->sign[index - 1]++;
            return index;
        }
        else {
            an->num[index] = val;
            an->sign[index] = 1;
            return index + 1;
        }
    }
}

int main() {
    int counta, countb;
    int a[20], b[20];
    arrNum numA;
    scanf("%d", &counta);
    for (int i = 0; i < counta; i++)
        scanf("%d", &a[i]);
    scanf("%d", &countb);
    for (int i = 0; i < countb; i++)
        scanf("%d", &b[i]);
    bubbleSort(a, counta);
    bubbleSort(b, countb);
    int indexN = 0, i = 0,j=0;
    for (; i < counta && j < countb;) {
        if (a[i] < b[j])
            indexN = putNum(&numA, a[i++], indexN);
        else if (a[i] > b[j])
            indexN = putNum(&numA, b[j++], indexN);
        else {
            i++;
            j++;
        }
    }
    while(counta-i)
        indexN = putNum(&numA, a[i++], indexN);
    while(countb-j)
        indexN = putNum(&numA, b[j++], indexN);
    for (int i = 0, count = 0; i < indexN; i++) {
        if (count == 0)
            printf("%d", numA.num[i]);
        else
            printf(" %d", numA.num[i]);
        count++;
    }
    return 0;
}


//法二，低效率：直接暴力查找
typedef struct arrNum {
    int num[40];
    int sign[40];
}arrNum;

int putNum(arrNum* an, int val, int index) {
    //第一个元素时，直接写入数组并修改标志位
    if (index == 0) {
        (*an).num[index] = val;
        an->sign[index] = 1;
        return 1;
    }
    else {
        //在结果数组中查找当前val是否存储过，如果存储过，标志位+1，直接返回index
        for (int i = 0; i < index; i++)
            if (val == an->num[i]) {
                an->sign[i]++;
                return index;
            }
        //未找到表示数组中无当前val，则插入该元素并修改标志位，然后返回下一个待插位置的下标(index+1)
        an->num[index] = val;
        an->sign[index] = 1;
        return index + 1;
    }
}

int main() {
    int counta, countb;
    int a[20], b[20];
    arrNum numA;
    scanf("%d", &counta);
    for (int i = 0; i < counta; i++)
        scanf("%d", &a[i]);
    scanf("%d", &countb);
    for (int i = 0; i < countb; i++)
        scanf("%d", &b[i]);

    int indexN = 0;
    //找a中有但b中没有的元素
    for (int i = 0; i < counta; i++) {
        int sgn = 1;
        for (int j = 0; j < countb; j++)
            if (a[i] == b[j]) {
                sgn = 0;
                break;
            }
        if (sgn)
            indexN = putNum(&numA, a[i], indexN);
    }
    //找b中有但a中没有的元素
    for (int i = 0; i < countb; i++) {
        int sgn = 1;
        for (int j = 0; j < counta; j++)
            if (b[i] == a[j]) {
                sgn = 0;
                break;
            }
        if (sgn)
            indexN = putNum(&numA, b[i], indexN);
    }
    //按格式输出
    for (int i = 0, count = 0; i < indexN; i++) {
        if (count == 0)
            printf("%d", numA.num[i]);
        else
            printf(" %d", numA.num[i]);
        count++;
    }
    return 0;
}


#if 0
/***输入n个朋友的信息，包括姓名、生日、电话号码，本题要求编写程序，按照年龄从大到小的顺序依次输出通讯录。题目保证所有人的生日均不相同。
输入格式:
输入第一行给出正整数n（<10）。随后n行，每行按照“姓名 生日 电话号码”的格式给出一位朋友的信息，其中“姓名”是长度不超过10的英文字母组成的字符串，“生日”是yyyymmdd格式的日期，“电话号码”是不超过17位的数字及+、-组成的字符串。
输出格式:
按照年龄从大到小输出朋友的信息，格式同输出。
输入样例:
3
zhang 19850403 13912345678
wang 19821020 +86-0571-88018448
qian 19840619 13609876543
结尾无空行
输出样例:
wang 19821020 +86-0571-88018448
qian 19840619 13609876543
zhang 19850403 13912345678
结尾无空行****/
typedef struct Person {
    char name[10];
    int birthday;
    char phonenum[17];
}Person;

int main() {
    int n;
    scanf("%d", &n);
    Person* pr[10];
    getchar();//这里getchar()可省略，因为下面使用scanf读取字符串，scanf()在读取到符合格式的内容之前忽略所有空白符
    for (int i = 0; i < n; i++) {
        pr[i] = (Person*)malloc(sizeof(Person));
        scanf("%s", pr[i]->name);
        scanf("%d", &pr[i]->birthday);
        getchar();//这里如果不加上getchar()会使phonenum前多一个空格，导致实际存储空间不足或者输出格式错误
        gets(pr[i]->phonenum);
        //getchar();//这里加getchar()会出错，导致除第一条信息外，后面各条信息的name都被吃掉首字母，为什么？
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1 - i; j++) {
            if (pr[j]->birthday > pr[j + 1]->birthday) {
                Person* prtem = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = prtem;
            }
        }
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%s %d %s\n", pr[i]->name, pr[i]->birthday, pr[i]->phonenum);
        else
            printf("%s %d %s", pr[i]->name, pr[i]->birthday, pr[i]->phonenum);
    }
    for (int i = 0; i < n; i++) {
        free(pr[i]);
    }
    return 0;
}


/***给定n本书的名称和定价，本题要求编写程序，查找并输出其中定价最高和最低的书的名称和定价。

输入格式:
输入第一行给出正整数n（<10），随后给出n本书的信息。每本书在一行中给出书名，即长度不超过30的字符串，随后一行中给出正实数价格。题目保证没有同样价格的书。
输出格式:
在一行中按照“价格, 书名”的格式先后输出价格最高和最低的书。价格保留2位小数。
输入样例:
3
Programming in C
21.5
Programming in VB
18.5
Programming in Delphi
25.0
结尾无空行
输出样例:
25.00, Programming in Delphi
18.50, Programming in VB
结尾无空行***/
typedef struct Book {
    char name[30];
    double price;
}Book;


int method1() {
    int n;
    scanf("%d", &n);
    Book* bk[10];
    getchar();//这里是为了吃掉int n后面的回车，否则第一个对象的name无法gets()
    for (int i = 0; i < n; i++) {
        bk[i] = (Book*)malloc(sizeof(Book));
        //scanf("%s", bk[i]->name);//出错，具体原因method2
        gets(bk[i]->name);
        scanf("%lf", &bk[i]->price);
        getchar();//漏掉会报错，详细解释看method3
    }
    Book* max = bk[0], * min = bk[0];
    for (int i = 0; i < n; i++) {
        if (max->price < bk[i]->price)
            max = bk[i];
        if (min->price > bk[i]->price)
            min = bk[i];
    }
    printf("%.2lf, %s\n%.2lf, %s", max->price, max->name, min->price, min->name);
    
    for (int i = 0; i < n; i++) {//注意这里，如果直接free(bk)会报错，因为free()的参数是指针，而bk是个指针数组。free的函数原型为：“void free(void *ptr)”。在这里malloc的是bk[0~9]，因此也用循环free掉bk[0~9]。
        free(bk[i]);
    }
    return 0;
}

void method2() {
    char str1[30], str2[30];
    scanf("%s", str1);//遇到空白符则停止读取(不包含空白符)
    gets(str2);//遇到回车结束（不包含回车）
    //所以输入整行时用gets()

    //printf()和puts()输出结果一样
    printf("scanf(str1):%s\ngets(str2):%s\n", str1, str2);
    puts(str1);
    puts(str2);
    return 0;
}

void method3() {
    Book* bk[3];
    for (int i = 0; i < 3; i++) {
        bk[i] = (Book*)malloc(sizeof(Book));
        gets(bk[i]->name);
        scanf("%lf", &bk[i]->price);
        getchar();//必须加上，在读第一个对象时，gets直接读到\n正确读取(此时\n未被gets，仍在缓冲区中)，然后scanf读的是数字，此时从缓存区中找数字，遇到空白符直接读取吃掉(因此输入数字时，空白符有多少无影响，这是stdio里设计的)。此时第一条读完（但注意，数字后的回车仍在缓冲区中，未被scanf读数字时读掉），当读第二条对象时，缓冲区第一个字符即回车，所以gets得到的内容为空，即'\0'.所以，当每次读完后必须getchar()把回车吃掉，再进行gets()，而gets()完字符串后，由于空白符(这里的回车)对下面scanf读数字无影响(stdio中已处理)，因此不必加getchar(),当然加了也行，不会报错，因为getchar吃掉的是回车而不是数字。
    }
    for (int i = 0; i < 3; i++) {
        printf("%s\t%.2lf\n", bk[i]->name, bk[i]->price);
    }
    return 0;
}

int main() {

    method1();
    //method2();
    //method3();
    return 0;
}
#endif



#if 0
/***本题要求编写程序，计算两个二维平面向量的和向量。
输入格式:
输入在一行中按照“x1 y1 x2 y2”的格式给出两个二维平面向量v1=(x1,y1)和v2=(x2,y2)的分量。
输出格式:
在一行中按照(x, y)的格式输出和向量，坐标输出小数点后一位（注意不能输出−0.0）。
输入样例:
3.5 -2.7 -13.9 8.7
结尾无空行
输出样例:
(-10.4, 6.0)
结尾无空行***/
int test1() {//错误，注意四舍五入
    float x1, x2, x, y1, y2, y;
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
    x = x1 + x2;
    y = y1 + y2;
    //输出格式
    if (fabs(x) - 0.1 < 0)
        printf("(0.0, ");
    else
        printf("(%.1f, ", x);
    if (fabs(y) - 0.1 < 0)
        printf("0.0)");
    else
        printf("%.1f)", y);
    return 0;
}
int main() {//正确，以-0.05为分界，四舍五入
    double x1, y1, x2, y2, x, y;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    x = x1 + x2;
    y = y1 + y2;
    if (x > -0.05)
        x = fabs(x);
    if (y > -0.05)
        y = fabs(y);
    printf("(%.1f, %.1f)", x, y);
    return 0;
}


/***本题要求编写程序，以hh:mm:ss的格式输出某给定时间再过n秒后的时间值（超过23:59:59就从0点开始计时）。
输入格式：
输入在第一行中以hh:mm:ss的格式给出起始时间，第二行给出整秒数n（<60）。

输出格式：
输出在一行中给出hh:mm:ss格式的结果时间。

输入样例：
11:59:40
30
结尾无空行
输出样例：
12:00:10
结尾无空行***/
/***本题要求编写程序，根据输入学生的成绩，统计并输出学生的平均成绩、最高成绩和最低成绩。建议使用动态内存分配来实现。
输入格式：
输入第一行首先给出一个正整数N，表示学生的个数。接下来一行给出N个学生的成绩，数字间以空格分隔。
输出格式：
按照以下格式输出：
average = 平均成绩
max = 最高成绩
min = 最低成绩
结果均保留两位小数。
输入样例：
3
85 90 95
结尾无空行
输出样例：
average = 90.00
max = 95.00
min = 85.00
结尾无空行****/
int main() {
    int h = 0, m = 0, s = 0, size;
    scanf("%d:%d:%d", &h, &m, &s);
    scanf("%d", &size);
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
        //记录进位，将size化为h:m:s
        int mt = 0, ht = 0;
        ht = size / 3600;
        size %= 3600;
        mt = size / 60;
        size %= 60;

        //从秒开始加法进位
        mt += (size + s) / 60;
        s = (size + s) % 60;
        ht += (m + mt) / 60;
        m = (m + mt) % 60;
        h = (h + ht) % 24;

        //输出格式
        if (h < 10)
            printf("0%d:", h);
        else
            printf("%d:", h);
        if (m < 10)
            printf("0%d:", m);
        else
            printf("%d:", m);
        if (s < 10)
            printf("0%d", s);
        else
            printf("%d", s);
    }
    return 0;
}




#define MAXS 9999
int main() {
    int n;
    double avg = 0, max = 0, min = 0;
    double* p[MAXS];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i] = malloc(sizeof(double));
        scanf("%lf", p[i]);
    }
    max = min = *p[0];
    for (int i = 0; i < n; i++) {
        avg += *p[i];
        if (max < *p[i])
            max = *p[i];
        if (min > *p[i])
            min = *p[i];
    }
    printf("average = %.2lf\nmax = %.2lf\nmin = %.2lf", avg / n, max, min);
    return 0;
}


/****本题要求编写程序，读入5个字符串，按由小到大的顺序输出。
输入格式：
输入为由空格分隔的5个非空字符串，每个字符串不包括空格、制表符、换行符等空白字符，长度小于80。

输出格式：
按照以下格式输出排序后的结果：

After sorted:
每行一个字符串
输入样例：
red yellow blue green white
结尾无空行
输出样例：
After sorted:
blue
green
red
white
yellow
结尾无空行****/
#include<string.h>
int main() {
    char* p[5];
    for (int i = 0; i < 5; i++)
        p[i] = malloc(sizeof(char[80]));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 80; j++) {
            scanf("%c", &p[i][j]);
            if (p[i][j] == ' ' || p[i][j] == '\n')
            {
                p[i][j] = '\0';
                break;
            }
        }
    printf("After sorted:\n");
    char* q;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 4 - i; j++) {
            if (strcmp(p[j], p[j + 1]) > 0)
            {
                q = p[j];
                p[j] = p[j + 1];
                p[j + 1] = q;
            }
        }
    for (int i = 0; i < 5; i++) {
        if (i != 4)
            printf("%s\n", p[i]);
        else
            printf("%s", p[i]);
    }
    return 0;
}


//#include<algorithm>
#define eps 1e-8
#define MAXS 6

double a[MAXS][MAXS], ans[MAXS];
int d;

void swap(double* p1, double* p2) {
    int tem = *p1;
    *p1 = *p2;
    *p2 = tem;
}

int gauss_jordan(int n) {//a为增广矩阵 
    int r, w = 0;
    for (int i = 0; i < n && w < n; w++, i++) {//进行到第i列，第w行 
        int r = w;
        for (int j = w + 1; j < n; j++)if (fabs(a[j][i]) > fabs(a[r][i]))r = j;//找到当前列绝对值最大的行 
        if (fabs(a[r][i]) < eps) { w--; continue; }//当前列值都为0,跨过当前步 
        if (r != w)for (int j = 0; j <= n; j++)swap(&a[r][j], &a[w][j]);//交换当前列绝对值最大的行和没计算过的第一行
        for (int k = 0; k < n; k++) {//消去当前列（除本行外）
            if (k != w)
                for (int j = n; j >= w; j--)a[k][j] -= a[k][i] / a[w][i] * a[w][j];
        }
    }
    return w;
}
int gauss(int n) {//a为增广矩阵  
    int  w=0;
    for (int i = 0; w < n && i < n; i++, w++) {//进行到第i列，第w行
        int r = w;
        for (int j = w + 1; j < n; j++)if (fabs(a[j][i]) > fabs(a[r][i]))r = j;//找到当前列绝对值最大的行 
        if (fabs(a[r][i]) < eps) { w--; continue; }//当前列值都为0,跨过当前步 
        if (w != r)for (int j = i; j <= n; j++)swap(&a[r][j], &a[w][j]);//交换当前列绝对值最大的行和没计算过的第一行 
        for (int k = w + 1; k < n; k++) {//消去当前列（只消下面行的） 
            double pro = a[k][i] / a[w][i];
            for (int j = i; j <= n; j++)
                a[k][j] -= pro * a[w][j];
        }
    }
    return w;
}
int main() {
    //freopen("gaess.txt", "r", stdin);
    //    freopen("gaess.out","w",stdout);
    int n; 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++) 
            scanf("%lf", &a[i][j]);

#if(0) //guass
    d = gauss(n); d--;
    for (int j = d; j < n; j++) {
        if (fabs(a[j][n - 1]) < eps && fabs(a[j][n]) > eps) { printf("-1"); return 0; }//最后一个方程未知数最少，方程=右边不为0=左边为0，则无解
    }
    if (d < n - 1) { printf("0"); return 0; }//一个方程解一个未知数，有效方程少于n个，则多个解 
    for (int i = d; i >= 0; i--) {
        for (int k = i + 1; k < n; k++)a[i][n] -= a[i][k] * ans[k];
        ans[i] = a[i][n] / a[i][i];
    }
#endif
//guass_jordan
    d = gauss_jordan(n); d--;
    for (int i = 0; i < n; i++) {//有一个方程=右边不为0=左边为0，则无解 
        int d = 1;
        for (int j = i; j < n; j++)d &= (fabs(a[i][j]) < eps);
        if (d && fabs(a[i][n]) > eps) {
            printf("-1"); return 0;
        }
    }
    for (int i = 0; i < n; i++) {//消元后有变量在多个方程中出现，则有多个解 
        int max1 = 0;
        for (int j = i; j < n; j++)if (fabs(a[i][j]) > eps)max1++;
        if (max1 > 1) { printf("0"); return 0; }
    }
    for (int i = 0; i < n; i++) {
        ans[i] = a[i][n] / a[i][i];
    }
#
    for (int i = 0; i < n; i++) {
        if (fabs(ans[i]) < eps)printf("x%d=0\n", i + 1);
        else printf("x%d=%.2lf\n", i + 1, ans[i]);
    }
    return 0;
}
#endif


#if(0)
/**习题4-10 猴子吃桃问题 (15 分)
一只猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个；第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下的一半加一个。到第N天早上想再吃时，见只剩下一个桃子了。问：第一天共摘了多少个桃子？
输入格式:
输入在一行中给出正整数N（1<N≤10）。
输出格式:
在一行中输出第一天共摘了多少个桃子。
输入样例:
3
输出样例:
10
****/
int main() {
    int n, sum = 1;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
        sum = (sum + 1) * 2;
    printf("%d", sum);
    return 0;
}


/**本题目要求编写程序统计一行字符中单词的个数。所谓“单词”是指连续不含空格的字符串，各单词之间用空格分隔，空格数可以是多个。
输入格式:
输入给出一行字符。
输出格式:
在一行中输出单词个数。
输入样例:
Let's go to room 209.
输出样例:
5
***/
int main() {
    char ch1, ch2;
    char s[500];
    int count = 0;
    gets(s);
    if (s) {
        for (int i = 0; s[i] != '\0'; i++) {
            ch1 = s[i];
            ch2 = s[i + 1];
            if (ch2 == '\0')
            {
                if (ch1 != ' ')
                    count++;
                break;
            }
            if (ch1 != ' ' && ch2 == ' ')
                count++;
        }
    }
    printf("%d\n", count);
    return 0;
}


//二维数组指针作为参数的测试
void test3(int a[],int k) {
    for (int i = 0; i < k / 2; i++) {//可以作用到原二维数组
        int tem = a[i];
        a[i] = a[k - 1 - i];
        a[k - 1 - i] = tem;
    }
}
void test2(int a[], int i) {//可以作用到原二维数组
    a[i] = 88;
}
void test1(int a[], int i) {//可以作用到原二维数组
    a[i] = 33;
    test2(a, i);
    test3(a, 3);
}

int main() {
    int m, n;
    int a[6][6];
    int* p[6];
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
        p[i] = a[i];

    test1(a + 1, 2);//可以改
    //test1(*(a + 1), 2);//可以改
    //test1(*a + 1, 2);//不可以改
    //test1(p[1], 2);//可以改

    for (int i = 0; i < n; i++) {
        if (i)
            printf("\n");
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
    }
    return 0;
}

/**本题要求编写程序，将给定n×n方阵中的每个元素循环向右移m个位置，即将第0、1、⋯、n−1列变换为第n−m、n−m+1、⋯、n−1、0、1、⋯、n−m−1列。
输入格式：
输入第一行给出两个正整数m和n（1≤n≤6）。接下来一共n行，每行n个整数，表示一个n阶的方阵。
输出格式：
按照输入格式输出移动后的方阵：即输出n行，每行n个整数，每个整数后输出一个空格。
输入样例：
2 3
1 2 3
4 5 6
7 8 9
输出样例：
2 3 1 
5 6 4 
8 9 7 
***/

void reverseA(int a[], int begin, int end) {//begin和end为数组下标
    for (int i = begin; i <= (begin+end)/2; i++) {//不要忘记等号
        int tem = a[i];
        a[i] = a[begin + end - i];
        a[begin + end - i] = tem;
    }
}

void moveright(int a[], int n, int m) {//n为数组长度，不是下标
    //右移m位
    reverseA(a, 0, n - 1 - m);
    reverseA(a, n - m, n - 1);
    reverseA(a, 0, n - 1);
}

int main() {
    int m, n;
    int a[6][6];
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    m %= n;
    for (int i = 0; i < n; i++)
        moveright(a + i, n, m);
    for (int i = 0; i < n; i++) {
        if (i)
            printf("\n");
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
    }
    return 0;
}


/**本题要求编写程序计算某年某月某日是该年中的第几天。
输入格式:
输入在一行中按照格式“yyyy/mm/dd”（即“年/月/日”）给出日期。注意：闰年的判别条件是该年年份能被4整除但不能被100整除、或者能被400整除。闰年的2月有29天。
输出格式:
在一行输出日期是该年中的第几天。
输入样例1:
2009/03/02
输出样例1:
61
输入样例2:
2000/03/02
输出样例2:
62
***/
int isry(int y) {
    if (y % 4 == 0 && y % 100 || y % 400 == 0)
        return 1;
    else
        return 0;
}
int monct(int y, int mon) {
    switch (mon) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2: {
        if (isry(y))
            return 29;
        else
            return 28;
    }
    default:
        return 0;
    }
}
int main() {
    int y, m, d, sum = 0;
    scanf("%d/%d/%d", &y, &m, &d);
    int sgn = m - 1;
    if (sgn) {
        while (sgn)
            sum += monct(y, sgn--);
    }
    sum += d;
    printf("%d", sum);
}


/**皮球从某给定高度自由落下，触地后反弹到原高度的一半，再落下，再反弹，……，如此反复。问皮球在第n次落地时，在空中一共经过多少距离？第n次反弹的高度是多少？
输入格式:
输入在一行中给出两个非负整数，分别是皮球的初始高度和n，均在长整型范围内。
输出格式:
在一行中顺序输出皮球第n次落地时在空中经过的距离、以及第n次反弹的高度，其间以一个空格分隔，保留一位小数。题目保证计算结果不超过双精度范围。
输入样例:
33 5
输出样例:
94.9 1.0
***/
double hi(double h, int n) {
    if (n == 0 || h == 0)
        return 0;
    if (n == 1)
        return h;
    else
        return hi(h / 2, n - 1);
}
int main() {
    int h, n;
    double sum = 0, lth = 0;
    scanf("%d%d", &h, &n);
    if (n == 0 || h == 0);
    else {
        lth = hi(h, n + 1);
        for (int i = 1; i <= n; i++)
            sum += 2 * hi(h, i);
        sum -= h;
    }
    printf("%.1lf %.1lf", sum, lth);
    return 0;
}


//最大公约数和最小公倍数
int main() {
    int m, n, gys = 1, gbs = 1;
    scanf("%d%d", &m, &n);
    int max = m > n ? m : n;
    int min = m < n ? m : n;
    //最大公约数
    for (int i = min; i > 1; i--)
        if (m % i == 0 && n % i == 0) {
            gys = i;
            break;
        }
    for (int i = max; 1; i++)
        if (i % m == 0 && i % n == 0) {
            gbs = i;
            break;
        }
    printf("%d %d\n", gys, gbs);
    return 0;
}
/**将一笔零钱换成5分、2分和1分的硬币，要求每种硬币至少有一枚，有几种不同的换法？
输入格式:
输入在一行中给出待换的零钱数额x∈(8,100)。
输出格式:
要求按5分、2分和1分硬币的数量依次从大到小的顺序，输出各种换法。每行输出一种换法，格式为：“fen5:5分硬币数量, fen2:2分硬币数量, fen1:1分硬币数量, total:硬币总数量”。最后一行输出“count = 换法个数”。
输入样例:
13
输出样例:
fen5:2, fen2:1, fen1:1, total:4
fen5:1, fen2:3, fen1:2, total:6
fen5:1, fen2:2, fen1:4, total:7
fen5:1, fen2:1, fen1:6, total:8
count = 4
***/

int main() {
    int money, count = 0, total = 0;
    scanf("%d", &money);
    for (int fen5 = 19; fen5 > 0; fen5--)
        for (int fen2 = 47; fen2 > 0; fen2--)
            for (int fen1 = 93; fen1 > 0; fen1--) {
                if (5 * fen5 + 2 * fen2 + fen1 == money) {
                    total = fen5 + fen2 + fen1;
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", fen5, fen2, fen1, total);
                    count++;
                }
            }
    printf("count = %d", count);
    return 0;
}


int main() {
    int val, count;
    //    srand(time(NULL));
    //    val=rand()%100+1;
    //    count=rand()%100+1;
    //    printf("%d %d",val,count);
    scanf("%d%d", &val, &count);
    int a[100];
    for (int i = 0; i < count; i++)
        scanf("%d", &a[i]);
    int vguss = 1;
    for (int i = 0; i < count; i++) {
        if (a[i] < 0)
            break;
        else if (a[i] > val) {
            printf("Too big\n");
            vguss++;
        }
        else if (a[i] < val) {
            printf("Too small\n");
            vguss++;
        }
        else {
            if (vguss == 1)
                printf("Bingo!\n");
            else if (vguss <= 3)
                printf("Lucky You!\n");
            else
                printf("Good Guess!\n");
            return 0;
        }
    }
    printf("Game Over\n");
    return 0;
}

//猜数字小游戏
int main() {
    int val, count;
    srand(time(NULL));
    val = rand() % 100 + 1;
    count = rand() % 100 + 1;
    //printf("%d %d",val,count);
    //printf("\n");
    int x;
    scanf("%d", &x);
    while (x >= 0 && count--) {
        int vguss = 0;
        if (x > val) {
            printf("Too big\n");
            vguss++;
        }
        else if (x < val) {
            printf("Too small\n");
            vguss++;
        }
        else {
            if (vguss <= 3)
                printf("Lucky You!\n");
            else
                printf("Good Guess!");
            return 0;
        }
        scanf("%d", &x);
    }
    printf("Game Over\n");
    return 0;
}

//C中随机数测试
#include<stdlib.h>//含rand()函数
#include<time.h>//含time()函数
int main()
{//运行结果：30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30
    //测试结果可能不同，但都是20个一样的数！为什么出现这种情况？
    int a;
    
    for (int i = 0; i < 20; i++) {
        srand(time(NULL));//以时间为参数种种子
        a = rand() % 100 + 1; //生成[1,100]直接的随机数
        printf("%-d ", a);
    }
    return 0;
}
// 若只用rand()进行随机数，而不用srand()作种，那也会产生一样的数。这是因为rand()函数产生的随机数是伪随机数，是根据一个数值按照某个公式推算出来的，而这个数值由一个公式计算得来，这个值在电脑启动后是不变的。在这里我将这个公式比作一个种子，所以我们就要使用srand()修改这个种子。

#include<stdlib.h>//含rand()函数,srand()函数
#include<time.h>//含time()函数
int main()
{//将srand()放在循环外，问题解决了。因为程序在运行时速度非常快，而time()是以秒为单位的，即每过一秒才更新一次。所以如果放在里面，每次for循环都会srand(x)同一个种子s，而x相同时，rand()的结果是相同的。
    //将srand()放在外面时，只会产生一个种子，for中rand()会根据一个种子产生一组的随机数。
    int a;
    srand(time(NULL));//以时间为参数种种子
    for (int i = 0; i < 20; i++) {
       
        a = rand() % 100 + 1; //生成[1,100]直接的随机数
        printf("%-d ", a);
    }
    return 0;
}
#endif




//#include<math.h>
//const double LEV = 1e-5;
//double jc(int n) {
//    if (n == 0)
//        return 1;
//    else
//        return n * jc(n - 1);
//}
//
//double zs(double x, int n) {
//    double sum = 1;
//    for (int i = 0; i < n; i++)
//        sum *= x;
//    return sum;
//}
//
//int main() {
//    double x, sum = 0, tem = 1;
//    scanf("%lf", &x);
//    for (int i = 0; tem-LEV>=0; i++) {
//       // double d1 = pow(x, i);
//        double d1 = zs(x, i);
//        double d2 = jc(i);
//        tem = d1 / d2;
//        sum += tem;
//    }
//    printf("%.4lf", sum);
//    return 0;
//}



//从字符串中提取十六进制字符并转换为十进制输出(若第一个字符前有'-'，则输出负数)
//int main() {
//    char s[100];
//    char ch = '#';
//    int sgn = 1, sum = 0;
//    gets(s);
//    for (int i = 0, j = 0; s[i] != '#'; i++, j++) {
//        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f')) {
//            if (sum == 0)
//                ch = s[i];
//            if (s[i] >= '0' && s[i] <= '9')
//                sum = sum * 16 + (s[i] - '0');
//            if (s[i] >= 'A' && s[i] <= 'F')
//                sum = sum * 16 + (s[i] - 'A' + 10) ;
//            if (s[i] >= 'a' && s[i] <= 'f')
//                sum = sum * 16 +(s[i] - 'a' + 10) ;
//        }
//    }
//    for (int i = 0; s[i] != ch; i++)
//        if (s[i] == '-') {
//            sgn = -1;
//            break;
//        }
//    if (sum)
//        printf("%d", sgn * sum);
//    else
//        printf("%d", sum);
//    return 0;
//}



/**将给定字符串中的大写英文字母按以下对应规则替换：
原字母	对应字母
A	Z
B	Y
C	X
D	W
…	…
X	C
Y	B
Z	A
输入格式：
输入在一行中给出一个不超过80个字符、并以回车结束的字符串。
输出格式：
输出在一行中给出替换完成后的字符串。
输入样例：
Only the 11 CAPItaL LeTtERS are replaced.
输出样例：
Lnly the 11 XZKRtaO OeGtVIH are replaced.
***/
//#include<stdio.h>
//int main() {
//    char ch[80];
//    char* str = &ch;
//    gets(str);
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] >= 'A' && str[i] <= 'Z')
//            str[i] = 155 - str[i];
//    }
//    puts(str);
//    return 0;
//}



#if(0)
/***习题7-5 找鞍点 (20 分)
一个矩阵元素的“鞍点”是指该位置上的元素值在该行上最大、在该列上最小。
本题要求编写程序，求一个给定的n阶方阵的鞍点。
输入格式：
输入第一行给出一个正整数n（1≤n≤6）。随后n行，每行给出n个整数，其间以空格分隔。
输出格式：
输出在一行中按照“行下标 列下标”（下标从0开始）的格式输出鞍点的位置。如果鞍点不存在，则输出“NONE”。题目保证给出的矩阵至多存在一个鞍点。
输入样例1：
4
1 7 4 1
4 8 3 6
1 6 1 2
0 7 8 9
输出样例1：
2 1
输入样例2：
2
1 7
4 1
输出样例2：
NONE
***/

//法1.有bug，不正确，在有并列极值元素且后面的极值元素位置为鞍点时会检测不出该鞍点。如：
//4
//13 7 4 12
//1 8 10 9
//6 10 5 11
//3 9 8 9
//int main() {
//    int n;
//    int a[6][6];
//    int max, min, col = 0, row = 0;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            scanf("%d", &a[i][j]);
//    for (int i = 0; i < n; i++) {
//        max = a[i][0];
//        for (int j = 0; j < n; j++)
//            if (max < a[i][j]) {
//                max = a[i][j];
//                col = j;
//            }
//        min = a[0][col];
//        for (int k = 0; k < n; k++) {
//            if (min > a[k][col]) {
//                min = a[k][col];
//                row = k;
//            }
//        }
//        if (max == min) {
//            printf("%d %d", row, col);
//            return 0;
//        }
//    }
//    printf("NONE");
//    return 0;
//}


//法2
int main() {
    int n;
    int a[6][6], b[6][6] = { 0 };//b为标志位数组
    int max, min, col = 0, row = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    //遍历每行找最大值，由于每行最值不唯一，便造成了法1的错误
    for (int i = 0; i < n; i++) {
        max = a[i][0];
        for (int j = 0; j < n; j++) 
            if (a[i][j] > max)
                max = a[i][j];
        //找到后遍历第i行，最值的位置在b中标记
        for (int k = 0; k < n; k++) {
            if (a[i][k] == max)
                b[i][k]++;//标记表示
        }
    }
    //同理，遍历每列找最小值
    for (int i = 0; i < n; i++) {
        min = a[0][i];
        for (int j = 0; j < n; j++)
            if (a[j][i] <min)
                min = a[j][i];
        //找到后遍历第i列，最值的位置在b中标记
        for (int k = 0; k < n; k++) {
            if (a[k][i] == min)
                b[k][i]++;//标记表示
        }
    }

    //遍历b数组，如果有鞍点，鞍点在b中的值必为2，否则没有
    int x = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            if (b[i][j] == 2) {
                x = 0;
                printf("%d %d", i, j);
            }
    if (x)//说明x未改变，即无鞍点
        printf("NONE");
    return 0;
}
#endif



#if(0)
/**判断一个给定的方阵是否上三角矩阵
* 输入格式：
输入第一行给出一个正整数T，为待测矩阵的个数。接下来给出T个矩阵的信息：每个矩阵信息的第一行给出一个不超过10的正整数n。随后n行，每行给出n个整数，其间以空格分隔。
输出格式：
每个矩阵的判断结果占一行。如果输入的矩阵是上三角矩阵，输出“YES”，否则输出“NO”。
输入样例：
3
3
1 2 3
0 4 5
0 0 6
2
1 0
-8 2
3
1 2 3
1 4 5
0 -1 6
输出样例：
YES
NO
NO
***/

int main() {
    int  count, n;
    int a[10][10];
    int b[200] = { 0 };
    //初始化时，只有第一个是{}里的值，后面全是0，所以如果={1}，则b[]里为{1,0 ,0 ...0}，因此初始化时括号填0更好，只要它没变，就说明它是上三角。
    scanf("%d", &count);
    for (int cn = 0; cn < count; cn++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (a[i][j] != 0) {
                    b[cn] = -1;
                    break;
                }
    }
    for (int i = 0; i < count; i++)
        if (b[i] == 0)
            printf("YES\n");
        else if (b[i] == -1)
            printf("NO\n");
    return 0;
}
#endif





#if(0)
/**给定一批整数，分析每个整数的每一位数字，求出现次数最多的个位数字。例如给定3个整数1234、2345、3456，其中出现最多次数的数字是3和4，均出现了3次。
输入格式：
输入在第1行中给出正整数N（≤1000），在第二行中给出N个不超过整型范围的非负整数，数字间以空格分隔。
输出格式：
在一行中按格式“M: n1 n2 ...”输出，其中M是最大次数，n1、n2、……为出现次数最多的个位数字，按从小到大的顺序排列。数字间以空格分隔，但末尾不得有多余空格
输入样例：
3
1234 2345 3456
输出样例：
3: 3 4***/

int main() {
    int n;
    int a[1000];
    int id[10] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        int num = a[i], remain = 0;
        if (num == 0)
            id[0]++;
        if (num < 0)
            num *= (-1);
        while (num) {
            remain = num % 10;
            num /= 10;
            id[remain]++;
        }
    }
    int max = id[0];
    for (int i = 1; i < 10; i++)
        if (max < id[i])
            max = id[i];
    printf("%d:", max);
    for (int i = 0; i < 10; i++)
        if (id[i] == max)
            printf(" %d", i);
    return 0;
}
#endif







#if(0)
//一级指针和二级指针的使用测试(链表为例)
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
}ListNode,*Linklist;

//创建链表(带头结点的尾插法)（一级指针）
ListNode* creatListbypost1_1(ListNode* L) {//正确，虽然所有东西都在该函数中进行和修改，而未对主函数的L进行改变，但最后用返回值传递了修改后的指针值，使得主函数中的L指向了该函数修改后被释放的L，也算对主函数的L进行了修改。而这里传进来的参数L有没有无所谓。因为它并不是主函数中的L，所以对它的修改目前只能在该函数中生效。

    //其实这里的head是多余的指针，可以从图中看出，只需要用L和rear就可以了。
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    L = head;
    ListNode* rear = L;
    printf("创建链表, 请输入数据(结束请输入-1)：\n");
    int x ;
    scanf("%d", &x);
    while (x != -1) {
        ListNode* s = (ListNode*)malloc(sizeof(ListNode));
        s->data = x;
        rear->next = s;
        rear = s;
        scanf("%d", &x);
    }
    rear->next = NULL;
    return L;
}

ListNode* creatListbypost1_2() {//正确，虽然所有东西都在该函数中进行和修改，而未对主函数的L进行改变，但最后用返回值传递了修改后的指针值，使得主函数中的L指向了该函数修改后被释放的L，也算对主函数的L进行了修改。
    ListNode* L = (ListNode*)malloc(sizeof(ListNode));
    ListNode* rear = L;
    printf("创建链表, 请输入数据(结束请输入-1)：\n");
    int x;
    scanf("%d", &x);
    while (x != -1) {
        ListNode* s = (ListNode*)malloc(sizeof(ListNode));
        s->data = x;
        rear->next = s;
        rear = s;
        scanf("%d", &x);
    }
    rear->next = NULL;
    return L;
}

void creatListbypost1_3(ListNode* L) {//错误。可以跟上面两个对比一下，因为传递的参数为指针的值传递，因此在该函数中只是修改了这里面的L，而未动主函数中的L，如果不把其中修改后的值返回给主函数，是无法改变主函数中的L的。

    //其实这里的head是多余的指针，可以从图中看出，只需要用L和rear就可以了。
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    L = head;
    ListNode* rear = L;
    printf("创建链表, 请输入数据(结束请输入-1)：\n");
    int x;
    scanf("%d", &x);
    while (x != -1) {
        ListNode* s = (ListNode*)malloc(sizeof(ListNode));
        s->data = x;
        rear->next = s;
        rear = s;
        scanf("%d", &x);
    }
    rear->next = NULL;
}

//创建链表(带头结点的尾插法)(二级指针或指针的引用"*&L",但C里面不能用引用，所以只能使用二级指针了)
void creatListbypost2_1(ListNode** L) {
    *L = (ListNode*)malloc(sizeof(ListNode));
    ListNode* rear = *L;
    int x;
    printf("创建链表, 请输入数据(结束请输入-1)：\n");
    scanf("%d", &x);
    while (x != -1) {
        ListNode* s = (ListNode*)malloc(sizeof(ListNode));
        s->data = x;
        rear->next = s;
        rear = s;
        scanf("%d", &x);
    }
    rear->next = NULL;
}




 
//输出链表
ListNode* displayList(ListNode* L) {
    printf("链表输出的结果为：\n");
    ListNode* s = L->next;
    while (s) {
        printf("%d ", s->data);
        s = s->next;
    }
   // printf("\n");
}

//修改链表(一级和二级指针的区别和使用)

//一级
ListNode* modefyList1(ListNode* L) {

}
void main() {
    ListNode* L=NULL;
    creatListbypost2_1(&L);
    displayList(L);

    free(L);
}



//链表操作
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

//函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。
//函数deletem将单链表L中所有存储了m的结点删除。返回指向结果链表头结点的指针。
struct ListNode* readlist();
struct ListNode* deletem(struct ListNode* L, int m);
void printlist(struct ListNode* L)
{
    struct ListNode* p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int m;
    struct ListNode* L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

typedef struct ListNode ListNode, * Linklist;
struct ListNode* readlist() {
    Linklist L = (Linklist)malloc(sizeof(ListNode));
    Linklist r = L;
    int x;
    scanf("%d", &x);
    while (x != -1) {
        Linklist s = (Linklist)malloc(sizeof(ListNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L->next;
};

struct ListNode* deletem(struct ListNode* L, int m) {
    //处理头节点
    Linklist tem;
    while (L && L->data == m) {
        tem = L;
        L = L->next;
        free(tem);
    }
    Linklist s = L, r = L;
    while (s) {
        if (s->data == m) {
            tem = s;
            r->next = s->next;
            s = s->next;
            free(tem);
        }
        else {
            r = s;
            s = s->next;
        }
    }
    return L;
}



/**函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。
函数getodd将单链表L中奇数值的结点分离出来，重新组成一个新的链表。返回指向新链表头结点的指针，同时将L中存储的地址改为删除了奇数
值结点后的链表的头结点地址（所以要传入L的指针）***/

struct ListNode* readlist();
struct ListNode* getodd(struct ListNode** L);
void printlist(struct ListNode* L)
{
    struct ListNode* p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* L, * Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}

struct ListNode* readlist() {
    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* rear = L;
    int x;
    scanf("%d", &x);
    while (x != -1) {
        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
        s->data = x;
        rear->next = s;
        rear = s;
        scanf("%d", &x);
    }
    rear->next = NULL;
    return L->next;//由于自带printfList是不含头节点的
}

struct ListNode* getodd(struct ListNode** L) {
    if (!(*L))
        return NULL;
    struct ListNode* T = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* rear = T;
    //单独处理头节点
    while ((*L)&&(*L)->data % 2) {//注意先判空才能取数，顺序不能颠倒
        rear->next = *L;
        rear = *L;
        *L = (*L)->next;
    }
    struct ListNode* preL = *L;
    struct ListNode* temL = *L;//因为创建链表时未返回头节点，所以创建的链表L实际上不含头节点
    while (temL) {
        if (temL->data % 2) {
            rear->next = temL;
            rear = temL;
            preL->next = temL->next;
        }
        else
            preL = temL;
        temL = temL->next;
    }
    rear->next = NULL;
    return T->next;
}
#endif






#if(0)
//字符串查找字串(暴力法)
//函数search在字符串s中查找子串t，返回子串t在s中的首地址。若未找到，则返回NULL
#include <stdio.h>
#define MAXS 30

char* search(char* s, char* t);
void ReadString(char s[]) { 
    gets(s);
}

int main()
{
    char s[MAXS], t[MAXS], * pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if (pos != NULL)
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

char* search(char* s, char* t) {
    int lths = 0, ltht = 0, id = -1;
    while (s[lths++] != '\0');
    while (t[ltht++] != '\0');
    if (lths - ltht >= 0) {
        int tem = ltht;
        for (int i = 0; s[i] != '\0'; i++) {
            id = i;
            int stem = i, j = 0;
            while (--tem && s[stem++] == t[j++]);
            if (tem == 0)
                return &s[id];
            else
                tem = ltht;
        }
    }
    return NULL;
}
#endif



#if(0)
//字符串连接，t放到s的后面
#include <stdio.h>
#include <string.h>

#define MAXS 10

char* str_cat(char* s, char* t);

int main()
{
    char* p;
    char str1[MAXS + MAXS] = { '\0' }, str2[MAXS] = { '\0' };

    scanf("%s%s", str1, str2);
    p = str_cat(str1, str2);
    printf("%s\n%s\n", p, str1);

    return 0;
}

char* str_cat(char* s, char* t) {//s+t
    int i = 0;
    while (s[i] != '\0') i++;
    int j = 0;
    while (t[j] != '\0')
        s[i++] = t[j++];
    s[i] = '\0';
    return s;
}

//有错
//char* str_cat(char* s, char* t) {//s+t
//    int i = 0;
//    while (s[i++] != '\0');
//    int j = 0;
//    //i--才行，因为上面i把'\0'也加上了
//    while (t[j] != '\0')
//        s[i++] = t[j++];
//    s[i] = '\0';
//    return s;
//}




//找出指向字符串的指针数组中，其指向字符串最长的字符串的长度
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10
#define MAXS 20

int max_len(char* s[], int n);

int main()
{
    int i, n;
    char* string[MAXN] = { NULL };

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        string[i] = (char*)malloc(sizeof(char) * MAXS);
        scanf("%s", string[i]);
    }
    printf("%d\n", max_len(string, n));

    return 0;
}


int max_len(char* s[], int n) {
    int max_lth = 0;
    for (int i = 0; i < n; i++) {
        int tem = 0;
        for (int j = 0; s[i][j] != '\0'; j++)  //for (int j = 0; (s+i)[j] != '\0'; j++)//错误，这是一维至臻首地址
        //for (int j = 0; *(*(s+i)+j) != '\0'; j++)//正确  //for (int j = 0; *(s+i)[j] != '\0'; j++) //错误   
            tem++;
        if (max_lth < tem)
            max_lth = tem;
    }
    return max_lth;
}
#endif

#if(0)

//递归的应用之(逆序输出）,(栈的特点)。参考下列两个例子(递归进行的逆序输出)

//例1. 将n的每一位数字从高位到低位顺序打印出来
void printdigits(int n) {
    if (n <= 9 && n >= 0)
        printf("%d\n", n);
    else {//考虑下面两句的前后顺序
        printdigits(n / 10);
        printf("%d\n", n % 10);
    }
}

//例2. 十进制转换为二进制输出
#include <stdio.h>
void dectobin(int n);
int main()
{
    int n;
    scanf("%d", &n);
    dectobin(n);
    return 0;
}
void dectobin(int n) {
    if (n < 2)
        printf("%d", n);
    else {//注意这两句的前后顺序，考虑为什么
        dectobin(n / 2);
        printf("%d", n % 2);
    }
}



//递归实现一个函数fn，计算下列简单交错幂级数的部分和：
//f(x, n) = x−x^2+ x^​3−x^4+ ⋯ + (−1)^(n−1)x^n​​
double powx(double x, int n) {
    if (n == 1)
        return x;
    else
        return x * powx(x, n - 1);
}

int sign(int n) {
    if (n % 2 == 0)
        return -1;
    else
        return 1;
}

double fn(double x, int n) {
    if (n == 1)
        return x * sign(n);
    else
        return powx(x, n) * sign(n) + fn(x, n - 1);
}


#include <stdio.h>
#define MAXS 20


//求[101,n](n为大于100小于1000的整数)区间内，有两位数字相同的完全平方数
int search(int n);

int main()
{
    int number;

    scanf("%d", &number);
    printf("count=%d\n", search(number));

    return 0;
}


int isIt(int n) {
    int remain[4];
    int i = 0;
    while (n) {
        remain[i++] = n % 10;
        n /= 10;
    }
    if (remain[0] == remain[1] || remain[0] == remain[2] || remain[2] == remain[1])
        return 1;
    return 0;
}

int search(int n) {
    int res[21];
    for (int i = 0, j = 11; i < 21; i++, j++)
        res[i] = j * j;
    int count = 0;
    for (int i = 101, j = 0; i < n + 1 && j < 21;) {
        if (res[j] > i)
            i++;
        else if (res[j] < i)
            j++;
        else {
            if (isIt(i))
                count++;
            i++;
            j++;
        }
    }
    return count;
}


//判断字符串是否回文
bool palindrome(char* s) {
    int lth = 0;
    while (s[lth++] != '\0');
    for (int i = 0, j = lth - 2; i < j; i++, j--) {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

//删除str中所有的c字符
void delchar(char* str, char c) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c)
            str[j++] = str[i];
    }
    str[j] = '\0';
}


//strcmpy函数
#include <stdio.h>
#define MAXN 20

void strmcpy(char* t, int m, char* s);
void ReadString(char s[]) /* 由裁判实现，略去不表 */ {
    int i = 0;
    while (scanf("%c", &s[i]) != EOF&&s[i]!='\n') i++;
    s[i] = '\0';
}

int main()
{
    char t[MAXN], s[MAXN];
    int m;

    scanf("%d\n", &m);
    ReadString(t);
    strmcpy(t, m, s);//strcpy()等C字符串函数不安全
    printf("%s\n", s);

    return 0;
}

void strmcpy(char* t, int m, char* s) {//t-->s
    int lth = 0;
    while (t[lth++] != '\0');
    if (m > lth || t == NULL)
        s = NULL;
    else {
        int i = m - 1, j = 0;
        while (t[i] != '\0') {
            s[j++] = t[i++];
        }
        s[j] = t[i];//'\0'
    }
}


//报数退出游戏
#include <stdio.h>
#define MAXN 20

void CountOff(int n, int m, int out[]);

int main()
{
    int out[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    CountOff(n, m, out);
    for (i = 0; i < n; i++)
        printf("%d ", out[i]);
    printf("\n");


    return 0;
}

//自解2  (有bug)
void CountOff2(int n, int m, int out[]) {
    int tem[MAXN], num[MAXN];
    for (int i = 0; i < n; i++) {
        num[i] = i + 1;
    }
    int pm=0,id=0,ni=0,sum=0;
    while (id < n) {
        ni %= n;
        if (num[ni] != -1) {
            pm++;
        }
        if (pm == m) {
            tem[id++] = num[ni];
            num[ni] = -1;
            pm = 0;
        }
        ni++;
        sum++;
    }
    printf("总次数： %d\n", sum);//11 3 ——84次
    for (int i = 0; i < n; i++) {//从1开始的out
        out[tem[i]] = i + 1;
    }
    //bug:因为这个原因，MAXN为20，但最多只能处理19个数据。（0空着，1~19只能用）
    for (int i = 0; i < n + 1; i++) {//前移移位，从0开始
        out[i] = out[i + 1];
    }
}



//自解1
void CountOff(int n, int m, int out[]) {
    int num[MAXN];
    for (int i = 0; i < n; i++) {
        num[i] = i + 1;
    }
    int count = 1, j = 0,pm=0;
    while (count <= n) {
        int i = (j % n);
        if (num[i] != -1) {
            pm++;
        }
        if (pm==m) {
            out[i] = count++;
            num[i] = -1;
            pm = 0;
        }
        j++;
    }
    //printf("总次数： %d\n",j);//11 3 ——84次
}



//网上版本
void CountOfft(int n, int m, int out[]) {
    int i, j, p;
    int num[MAXN];

    for (i = 0; i < n; i++) {
        num[i] = i + 1;
    }

    int count = 0,sim=0;
    i = 0, j = 0, p = 0;
    while (count < n) {
        if (num[i] != -1) {
            p++;
        }
        if (p == m) {
            j++;
            out[i] = j;
            p = 0;
            num[i] = -1;
            count++;
        }
        i++;
        sim++;
        if (i == n) {
            i = 0;
        }
    }
    printf("总次数： %d\n", sim);//11 3 ——84次
}


void CountOfftt(int n, int m, int out[]) {
    int i, j;
    int tem[MAXN];
    int num[] = {-1,3,6,9,1,5,10,4,11,8,2,7};
    for (i = 1; i < n+1; i++) {
        tem[num[i]] = i;
    }
    printf("num:\n");
    for (j = 1; j < n+1; j++) {
        printf("%d ",num[j]);
    }
    printf("\ntem:\n");
    for (j = 1; j < n+1; j++) {
        printf("%d ", tem[j]);
    }
}
#endif



#if(0)
//数组元素右移m位
#include <stdio.h>
#define MAXN 10
int ArrayShift(int a[], int n, int m);

int main()
{
    int a[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    ArrayShift(a, n, m);

    for (i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}

void reverseA(int a[], int begin, int end) {
    int mid = (begin + end) / 2;
    for (int i = begin; i <= mid; i++) {
        int tem = a[i];
        a[i] = a[begin + end - i];
        a[begin + end - i] = tem;
    }
}

int ArrayShift(int a[], int n, int m) {
    reverseA(a, 0, n - m - 1);
    reverseA(a, n - m, n - 1);
    reverseA(a, 0, n - 1);
    return 0;
}
#endif




#if(0)

#include <stdio.h>

int narcissistic(int number);
void PrintN(int m, int n);

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    if (narcissistic(m)) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if (narcissistic(n)) printf("%d is a narcissistic number\n", n);

    return 0;
}


//水仙花数
#include<math.h>
int narcissistic(int number) {
    int remain = 0, sum = 0,num=number;
    if (num >= 100 && num <= 999) {
        while (num) {
            remain = num % 10;
            num = num / 10;
            sum += pow(remain, 3);
        }
    }
    else {
        while (num) {
            remain = num % 10;
            num = num / 10;
            sum += pow(remain, 4);
        }
    }
    if (sum == number)
        return 1;
    return 0;
}
void PrintN(int m, int n) {
    for (int i = m; i < n; i++) {
        if (narcissistic(i))
            printf("%d\n", i);
    }
}
#endif