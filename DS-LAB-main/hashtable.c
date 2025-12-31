#include<stdio.h>
#define MAX 20
int hashTable[20];
int m;
void insert(int key) {
    int index=key%m;
    if (hashTable[index]==-1) {
        hashTable[index]=key;
    }
    else {
        int i=1;
        while (hashTable[(index+i)%m] != 1)
        {
            i++;
        }
        hashTable[(index+i)%m]=key;

    }

}
void display() {
    printf("\n Hash Table : \n");
    for (int i=0;i<m;i++) {
        if (hashTable[i]!=-1) {
            printf("Address %d : %d\n",i,hashTable[i]);

        }
        else {
            printf("Address %d : Empty\n",i);
        }
    }
}
int main() {
    int n,key;
    printf("Enter the size of the hash table : \n");
    scanf("%d",&m);
    printf("Enter the number of employee records \n");
    scanf("%d",&n);
    for (int i=0;i<m;i++) {
        hashTable[i]=-1;
    }
    printf("Enter %d employees keys (4-digits):\n",n);
    for (int i=0;i<n;i++) {
        scanf("%d",&key);
        insert(key);
    }

display();


}
