#include<cstdio>
#include<algorithm>
using namespace std;

int a[101];//存放待交换的所有数
int p[101];//位置数组

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
        }
        for(int j = 1;j <= m;j++){
            scanf("%d",&p[j]);
        }
        sort(p + 1,p + m + 1); //将p位置数组排序，获得最小位置与最大位置
        sort(a + p[1],a + p[m]); // 将p数组中在A中的所有位置上排序
        bool flag = false;
        if(p[1] > 1){
            for(int i = 1;i < p[1];i++){  // 若最小交换位置的数字，不是第一个且前面的不能交换到的数字有降序存在或比最小交换位置上的数大，则结果为“NO”
                if(a[i] > a[i + 1]){
                    flag = true;
                    break;
                }
            }
        }
        if(p[m] < n - 1){
            for(int i = n;i > p[m];i--){  //// 若最大交换位置的数字，不是小于倒数第二个且后面的所有不能交换到的数字有降序存在或比最大交换位置上的数小，则结果为“NO”
                if(a[i] < a[i - 1]){
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
