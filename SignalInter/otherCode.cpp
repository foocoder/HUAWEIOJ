 #include <iostream>
#include <cstdlib>
using namespace std;
typedef struct Node
{
 int a;
 int b;
 struct Node *next;
}Node,*LinkList;

LinkList Build(LinkList L,int m) //建立单向链表
{
 LinkList p,q;
 p=L;
 while(m--)
 {
  q=(LinkList)malloc(sizeof(Node));
  cin>>q->a>>q->b;
  q->next=NULL;
  p->next=q;
  p=q;
 }
 return L ;
}

LinkList DeleteSameElem(LinkList L) //相邻的重复元素，删除后者保留前者
{
 LinkList p,q;//,s;
 p=L;
 q=L->next;
 while(q->next)
 {

  if(q->a==q->next->a)
  {
   /*
   p->next=q->next;
   s=q;
   q=q->next;
   free(s);
   */
   p=q->next;
   q->next=p->next;
   free(p);

  }
  else
  {
   //p=p->next;
      q=q->next;
  }
 }
 return L ;
}

void LineInsert(LinkList L,int m)
{
    LinkList p=L->next,q;
 while(p->next!=NULL) //注意不是while(p!=NULL) 因为后面涉及到p->next->next
 //for(int i=1;i<m;i++)
 {   /*
        if(p->a==p->next->a)
  {
   q=p->next;
   p->next=p->next->next;
   free(q);
  }
  else */

  if(((p->next->a)-(p->a))>1)
  {
   int d=(p->next->a)-(p->a)-1;
   int A=p->b;
   int B=p->next->b;
   int M=p->a;
   int N=p->next->a;
   for(int i=1;i<=d;i++)
   {
    q=(LinkList)malloc(sizeof(Node));
    q->a=p->a+1; //不是 q->a=M+1;
    q->b=A+(B-A)/(N-M)*i;
    q->next=p->next;
    p->next=q;
    p=q;
   }

  }
      p=p->next;
 }
}
void DisplayList(LinkList L)
{
 LinkList p=L->next;
 while(p!=NULL) //不是while(p->next!=NULL)
 {
        cout<<p->a<<" "<<p->b<<endl;
  p=p->next;
 }
}
int main()
{
 int m,n;
 cin>>m>>n;
 LinkList L=(LinkList)malloc(sizeof(Node));
 L->next=NULL;
 L->a=-11;
 L->b=-11;
 Build(L,m);
 DeleteSameElem(L);
    //pur_LinkList(L);
 LineInsert(L,m);
 DisplayList(L);

 return 0;
}
