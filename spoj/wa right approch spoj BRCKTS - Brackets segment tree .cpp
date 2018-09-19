
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef  long long ll;

string s;

struct node {
    int open=0, close=0;
};
struct node tree[30005<<2 +5];

node build(int b, int e, int node) {
//    printf("b %d e %d node %d\n", b, e, node);
    struct node & t = tree[node];
    if(b==e) {
//        printf("ret %d\n",( (s[b-1] == '(') ? 1:-1 ) );
//        printf("before b %d  open %d close %d\n", b, t.open, t.close);
        if(s[b-1] == '(') t.open=1;
        else t.close=1;  ;
//        printf("after  b %d  open %d close %d\n", b, t.open, t.close);
        return tree[node];
    }
    int left = node<<1;
    int right = left+1;
    int mid = (b+e)/2;
    struct node l,r;
    l = build(b, mid, left);
    r = build(mid+1, e, right);
    int x =  min(l.open, r.close);

    l.open -= x;
    r.close-= x;

    t.open = l.open + r.open;
    t.close = l.close + r.close;
//    printf("b %d e %d open %d close %d\n", b,e,t.open, t.close );
    return tree[node];


}

node update(int b, int e, int node, int k) {
    struct node & t = tree[node];
//    printf("b %d e %d k %d\n", b, e, k);
    if(b>k || e<k) return tree[node];
//    printf("aise\n");

    if(b==e) {
//        printf("before b %d  open %d close %d\n", b, t.open, t.close);

         if(t.open == 1) {
            t.open=0; t.close=1;
         } else {
            t.open=1; t.close=0;
         }
//        printf("after b %d  open %d close %d\n", b, t.open, t.close);
        return t;
    }
    int left = node<<1;
    int right = left+1;
    int mid = (b+e)/2;

    struct node l,r;
    l = update(b, mid, left, k);
    r = update(mid+1, e, right, k);
    int x =  min(l.open, r.close);

    l.open -= x;
    r.close-= x;

    t.open = l.open + r.open;
    t.close = l.close + r.close;
//    printf("b %d e %d open %d close %d\n", b,e,t.open, t.close );
    return tree[node];


}

int query(int b, int e, int node) {
    struct node &t = tree[node];
//    if(b==e) {
//        return tree[node] = ( (s[b-1] == '(') ? 1:-1 ) ;
//    }
//    int left = node<<1;
//    int right = left+1;
//    int mid = (left+right)/2;
//
//    int l = build(b, mid, left);
//    int r = build(mid+1, e, right);
//
//    if(l<0) tree[node] = -1;
//    else tree[node] = l+r;

    return (tree[node].open == tree[node].close && tree[node].open ==0);


}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);    cin.tie(0);

    int t, tc;
//    cin>>t;
    int n, m, k;
//    cin.ignore();
    for(tc=1;cin>>n>>s>>m ; tc++) {

//        cout<<n<<","<<s<<","<<m<<endl;
        build(1, n, 1);
        cout<<"Test "<<tc<<":"<<endl;
        while(m--) {
             cin>>k;
             if(!k) {
//                printf("query tree[1] %d\n", tree[1]);
                if(query(1, n, 1)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
             } else {
                update(1, n, 1, k);
             }
        }
//        break;
    }


    return 0;
}





//
//cd "C:\Program Files\Oracle\VirtualBox\"
//VBoxManage.exe modifyvm "macOS 10.12 sierra" --cpuidset 00000001 000106e5 00100800 0098e3fd bfebfbff
//VBoxManage setextradata "macOS 10.12 sierra" "VBoxInternal/Devices/efi/0/Config/DmiSystemProduct" "iMac11,3"
//VBoxManage setextradata "macOS 10.12 sierra" "VBoxInternal/Devices/efi/0/Config/DmiSystemVersion" "1.0"
//VBoxManage setextradata "macOS 10.12 sierra" "VBoxInternal/Devices/efi/0/Config/DmiBoardProduct" "Iloveapple"
//VBoxManage setextradata "macOS 10.12 sierra" "VBoxInternal/Devices/smc/0/Config/DeviceKey" "ourhardworkbythesewordsguardedpleasedontsteal(c)AppleComputerInc"
//VBoxManage setextradata "macOS 10.12 sierra" "VBoxInternal/Devices/smc/0/Config/GetKeyFromRealSMC" 1
//
//VBoxManage controlvm "macOS 10.12 sierra" setvideomodehint 1366 768 32
//VBoxManage.exe setextradata "macOS 10.12 sierra" CustomVideoMode1 1366x768x32
//
//
//VBoxManage setextradata global GUI/MaxGuestResolution any
//VBoxManage setextradata "macOS 10.12 sierra" "CustomVideoMode1" "1366x768x32"
