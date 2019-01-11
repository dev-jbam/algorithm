/*

1242.cpp
어떤 국가에서는 자국 내 방송국에서 스파이가 활동하는 사실을 알아냈다.

스파이는 영상물에 암호 코드를 삽입하여 송출하고 있었다.

암호 코드는 국가 내 중요 시설을 의미하는 숫자임을 알아냈다. 암호 코드의 규칙은 아래와 같다.
 

1. 총 8개의 숫자로 이루어져 있다.

2. 앞 7자리는 상품 고유의 번호를 나타내며, 마지막 자리는 검증 코드를 나타낸다.

    - 검증코드는 아래와 같은 방법으로 계산한다.

    “(홀수 자리의 합 x 3) + 짝수 자리의 합 + 검증 코드” 가 10의 배수가 되어야 한다.

    상품 고유의 번호가 8801234일 경우,

    “( ( 8 + 0 + 2 + 4 ) x 3 ) + ( 8 + 1 + 3 ) + 검증 코드”

    = “42 + 12 + 검증 코드”

    = “54 + 검증 코드” 가 10 의 배수가 되어야 하므로, 검증코드는 6이 되어야 한다.

    즉, 88012346 이 정상적인 암호코드고, 그 외의 검증코드가 포함된 경우 비정상적인 암호코드다.

A 업체에서는 이 암호코드들을 빠르고 정확하게 인식할 수 있는 스캐너를 개발하려고 한다. 스캐너의 성능은 아래와 같은 방법으로 측정된다.
 
1. 세로 2000. 가로 500 이하의 크기를 가진 직사각형 배열에 암호코드 정보가 포함되어 전달된다. 이 때, 하나의 배열에는 1개 이상의 암호코드가 존재한다. (단, 모든 암호코드가 정상적인 암호코드임을 보장할 수 없다. 비정상적인 암호코드가 포함될 수 있다.)

2. 배열은 16진수로 이루어져 있으며, 이 배열을 2진수로 변환하여 그 안에 포함되어 있는 암호코드 정보를 확인한다.

3. 포함된 암호코드들의 검증코드를 확인하여 정상적인 암호코드인지 확인한다.

4. 정상적인 암호코드들을 판별한 뒤 이 암호코드들에 적혀있는 숫자들의 합을 출력한다.

5. 이때, 총 소요시간이 적을수록 성능이 좋은 것으로 간주된다.

배열에 포함되어 있는 암호코드의 세부 규칙은 아래와 같다.
 
1. 암호코드 하나는 숫자 8개로 구성되며 시작 구분선, 종료 구분선은 별도로 존재하지 않는다.

2. 암호코드들이 붙어있는 경우는 존재하지 않는다. (각 암호코드의 둘레에는 최소 1칸 이상의 빈 공간이 존재한다.)

3. 암호코드가 일부만 표시된 경우는 없다. 모든 암호코드는 8개의 숫자로 구성되어 있다.

4. 암호코드의 세로 길이는 5 ~ 100 칸이다.

5. 암호코드의 가로 길이는 암호코드 선의 두께에 따라 달라지며, 두께가 가장 가는 경우, 숫자 하나가 차지하는 길이는 7칸 이다. 각 숫자들을 그림으로 표시하는 방법은 다음과 같다.
 


각 숫자는 흰색과 파란색의 넓이 비로 표현된다. 암호코드의 가로 길이가 길어질 경우, 숫자 하나가 차지하는 길이는 7의 배수가 된다. 예를 들어, 가로 길이가 2배가 될 경우 9는 아래와 같이 표시될 수 있다.
 


6. 암호코드 하나의 최소 가로 길이는 56이며, 암호코드 선이 굵어질 경우, 56의 배수의 길이를 갖게 된다. 예를 들어 암호코드 숫자 하나가 14칸을 사용하는 경우, 암호코드 하나의 가로길이는 112가 된다. 암호코드 하나에 포함되는 암호코드 숫자들은 모두 동일한 크기를 갖는다.
암호코드 정보가 포함된 2차원 배열을 입력으로 받아 정상적인 암호코드를 판별하는 프로그램을 작성하라.

[입력]

표준 입력으로 T개의 테스트 케이스가 이어져서 주어진다.

각 테스트 케이스의 첫 줄에 두 자연수가 주어지는데 각각 배열의 세로 크기 N, 배열의 가로크기 M이다 (1≤N<2000, 1≤M<500).

그 다음 N 개의 줄에는 M개의 배열의 값이 주어진다. 문제의 모든 배열의 값은 16진수이다.

[출력]

각 테스트 케이스의 답을 순서대로 표준출력으로 출력하며, 각 케이스마다 줄의 시작에 “#C”를 출력하여야 한다. 이때 C는 케이스의 번호이다.

같은 줄에 빈칸을 하나 두고, 입력에 주어진 배열에서 정상적인 암호코드들에 포함된 숫자들의 합을 출력한다.

[참고]

각 테스트 케이스의 구성은 아래와 같다. 
 
테스트 케이스	 N * M	암호코드 가로 길이	암호코드 개수
그룹 1	100 * 26	56	1
그룹 2	200 * 50	56 ~ 112	2
그룹 3	500 * 126	56 ~ 280	5
그룹 4	1000 * 250	제한 없음	제한 없음
그룹 5	2000 * 500	제한 없음	제한 없음

[예제 풀이]

1번 케이스의 암호코드 정보를 변환하면 아래와 같다.

01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
01110110110001011101101100010110001000110100100110111011
 
이 숫자가 나타내는 정보는 각각 아래와 같다.
0111011(7) 0110001(5) 0111011(7) 0110001(5) 0110001(5) 0001101(0) 0010011(2) 0111011(7)
 
검증코드가 맞는지 살펴보면, (7 + 7 + 5 + 2) * 3 + 5 + 5 + 0 + 7 = 80 이므로 올바른 암호코드라고 할 수 있다. 따라서 1번의 출력 값은 38이 된다.
 
2번 케이스도 같은 방식으로 계산할 경우, 328D1AF6E4C9BB 는 14468227 이 되며, 검증코드가 틀렸음을 알 수 있다.

196EBC5A316C578 는 18694956이 되며, 검증코드가 맞음을 알 수 있다.

따라서 2번의 출력 값은 올바른 암호코드인 18694956의 값만 더한 48이 된다.


#입력

2
16 26
00000000000000000000000000
00000000000000000000000000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
000000001DB176C588D26EC000
00000000000000000000000000
00000000000000000000000000
18 50
00000000000000000000000000000000000000000000000000
00000000000000000000000000000000000000000000000000
000000000000000000000000000196EBC5A316C57800000000
000000000000000000000000000196EBC5A316C57800000000
000000328D1AF6E4C9BB0000000196EBC5A316C57800000000
000000328D1AF6E4C9BB0000000196EBC5A316C57800000000
000000328D1AF6E4C9BB0000000196EBC5A316C57800000000
000000328D1AF6E4C9BB0000000196EBC5A316C57800000000
000000328D1AF6E4C9BB0000000196EBC5A316C57800000000
000000328D1AF6E4C9BB0000000196EBC5A316C57800000000
000000328D1AF6E4C9BB0000000196EBC5A316C57800000000
000000328D1AF6E4C9BB0000000196EBC5A316C57800000000
000000328D1AF6E4C9BB0000000196EBC5A316C57800000000
000000328D1AF6E4C9BB0000000196EBC5A316C57800000000
000000000000000000000000000196EBC5A316C57800000000
000000000000000000000000000196EBC5A316C57800000000
00000000000000000000000000000000000000000000000000
00000000000000000000000000000000000000000000000000
 
출력
#1 38
#2 48
s
*/

#if 0
 
#include <stdio.h>
 
#define MAX_N 2000
#define MAX_M 501
 
#define HEXA_BITS 4
#define BINARY_MAX HEXA_BITS * MAX_M
 
#define CODE_LEN 7
#define CODE_CNT 8
 
char numbers[10][10] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };
 
 
char inputs[MAX_N][MAX_M];
char bistrs[MAX_N][BINARY_MAX];
int bistrLen[MAX_N];
 
void strCpy(char *lv, const char* rv){
    int i = 0;
    while (rv[i]){
        lv[i] = rv[i];
        i++;
    }
    lv[i] = 0;
}
int Strlen(char *str){
    int i = 0;
    while (str[i]){
        i++;
    }
    return i;
}
 
bool Strcmp(char *a, char *b){
    int i = 0, j = 0;
     
    if (a[0] == 0 || b[0] == 0){
        return a[0] == b[0];
    }
 
    while (a[i] && b[j]){
        if (a[i] !=b[j]){
            return false;
        }
        ++i, ++j;
    }
 
    return true;
}
 
void inputCleaner(char *prev, char *input){
 
    int i = 0;
 
    while (prev[i] && input[i]){
        if (prev[i] == input[i]){
            input[i] = '0';
        }
        ++i;
    }
 
}
 
bool Strcmp(const char *a, const char *b, int sameCount){
    int i = 0, j = 0;
 
    while (a[i] && b[j]){
        if (a[i] != b[j]){
            return false;
        }
        for (int skip = 1; skip < sameCount; ++skip){
            if (b[j] != b[j + skip]){
                return false;
            }
        }
        ++i; j += sameCount;
    }
 
    return true;
}
 
int hexaCharToDecimal(char hxVal){
    if ('0' <= hxVal  && hxVal <= '9') {
        return hxVal - '0';
    }
    else if ('A' <= hxVal  && hxVal <= 'F') {
        return hxVal - 'A' + 10;
    }
    else if ('a' <= hxVal  && hxVal <= 'f') {
        return hxVal - 'a' + 10;
    }
 
    return -1;
}
 
void hexaToBinary(char *lval, int hexaVal){
     
    int idx = HEXA_BITS;
    lval[idx--] = 0;
    while (hexaVal){
        lval[idx] = hexaVal % 2 ? '1' : '0';
        --idx;
        hexaVal /= 2;
    }
    while (idx > -1){
        lval[idx] = '0';
        --idx;
    }
     
 
}
 
int convertHexaToBinary(char *input, char* binary){
    int i = 0;
 
    for (i = 0; input[i]; ++i){
        int hexaVal = hexaCharToDecimal(input[i]);
        if (hexaVal == -1){
            return NULL;
        }
        hexaToBinary(binary + i * HEXA_BITS, hexaVal);
    }
 
    binary[i * HEXA_BITS] = 0;
    return i*HEXA_BITS;
}
 
 
int validate(int arr[]){
    int checker = 0;
    int ret = 0;
    for (int i = 0; i < 7; i++){
        ret += arr[i];
        if (i % 2){
            checker += arr[i];
        }
        else{
            checker += (arr[i] * 3);
        }
    }
    int mod = checker % 10;
 
    if ((mod + arr[7]) % 10 != 0){
        return -1;
    }
 
    return ret + arr[7];
 
 
}
 
int try_check(char * bistr, int h, int sameCount){
 
    int ans = 0;
    int count = 0;
    int arr[8];
 
    for (int i = 0; i < 8; i++){
        int start = i*CODE_LEN*sameCount;
        for (int k = 0; k < 10; k++){
            if (Strcmp(numbers[k], bistr + start, sameCount)){
                arr[i] = k;
                count++;
            }
        }
        if ((count - 1) != i){
            return -1;
        }
    }
 
    return validate(arr);
}
 
int checkCodeProgram(int n, int m){
 
    for (int i = 0; i < n; ++i){
        bistrLen[i] = convertHexaToBinary(inputs[i], bistrs[i]);
    }
 
    int ans = 0;
    for (int sameCount = 1; sameCount*CODE_LEN*CODE_CNT <= m * HEXA_BITS; sameCount++){
        int codesLen = (CODE_LEN*CODE_CNT * sameCount);
         
        for (int i = 0; i < n; ++i){
            int k_limit = bistrLen[i] - codesLen;
         
            for (int k = 0; k < k_limit; ++k){
                if (bistrs[i][(k + codesLen - 1)] == '1'){
                    int ret = try_check(bistrs[i] + k, i, sameCount);
                    if (ret != -1){
                        ans+= ret;
                    }
                }
            }
        }
 
    }
 
    return ans;
 
}
int main(){
 
    int test_case;
 
    //freopen("sample_code2.txt", "r", stdin);
    scanf("%d", &test_case);
 
    for (int t = 1; t <= test_case; t++){
        int n, m;
        scanf("%d %d", &n, &m);
        char prev[MAX_M] = "";
        char cur[MAX_M] = "";
        int idx = 0;
        for (int i = 0; i < n; i++){
            scanf("%s", cur);
            if (!Strcmp(prev, cur) ){
                strCpy(inputs[idx],cur);
                inputCleaner(prev, inputs[idx]);
                strCpy(prev, cur);
                idx++;
            }
        }
         
        int ans = checkCodeProgram(idx, m);
         
        printf("#%d %d\n", t, ans);
    }
    return 0;
 
}
 
#endif