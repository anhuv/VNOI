#include<cstdio>
#include<algorithm>
#include <iostream>
#include<cmath>
using namespace std;

typedef long long ll;
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
//Ham kiem tra 1 sô a có uoc i thoa man (a%i^2=0)
bool Test(ll a){
	for(ll i=2;i<=sqrt(a);i++){
		ll b=pow(i,2);
		if(a%b==0) return true;
	}
	return false;
}
void merge(ll arr[], ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;
    ll L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(ll arr[], ll l, ll r)
{
    if (l < r)
    {
 
        ll m = l+(r-l)/2;
 
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
int main(){
	ll n;
	cin>>n;
	ll A[10001];//Mang A luu cac uoc cua so n
	int dem=0;
	for(ll i=2;i<=sqrt(n);i++){
		if(n%i==0&&i!=n/i){
			A[dem]=i;
			A[dem+1]=n/i;
			dem+=2;
		}
		if(i==n/i&&n%i==0){
			A[dem]=i;
			dem++;
		}
	}
	A[dem]=1;
	A[dem+1]=n;
	dem+=2;
	//Sap xep mang A theo thu tu tang dan
	mergeSort(A,0,dem-1);
	for(ll i=dem-1;i>=0;i--){
		if(Test(A[i])==false){//Xet lan luot mang A neu phan tu A[i] nao khong co uoc thoa man (A[i]%a^2=0) thì in ra va thoát
			cout<<A[i]<<endl;
			break;
		} 
	}
	return 0;
}
