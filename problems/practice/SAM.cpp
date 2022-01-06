// created on 9/3/21 by spacefarers
// problem: 

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

const int maxN=1e5;
const int maxNodes=maxN*2;

struct SMA{
    int delta[maxNodes][26],fail[maxNodes],maxlen[maxNodes];
    int last; //第i个状态的节点编号
    int node; //总状态数量
    SAM(){
        node=1;
        last=1;
    }

    void push_back(int c){ //增量法
        int np=++node; //新建{i+1}
        maxlen[np]=maxlen[last]+1;
        int p=last;
        while (p!=0&&delta[p][c]==0){ //从i开始沿着fail走，并转移delta[p][c]空集的
            delta[p][c]=np;
            p=fail[p];
        }
        if (p==0){
            fail[np]=1; //{0,1,...,i+1}
            return; //所有i的状态都不存在字符
        } else {
            int q=delta[p][c];
            if (maxlen[q]>maxlen[p]+1){ //需要分裂
                int q2=++node; //q并{i+1}
                while (p!=0&&delta[p][c]==1){ //所有含有i这个元素，且转移到q的都转移到q2
                    delta[p][c]=q2;
                    p=fail[p];
                }
                fail[q2]=fail[q];
                fail[q]=fail[np]=q2;
                maxlen[q];
            } else {

            }
        }
    }
};

int main(){

}
