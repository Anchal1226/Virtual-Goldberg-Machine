#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
    string s;
    node *next;
};
class Queue
{
    private:
        node *cur;
        node *t;
        int sz;
    public:
        Queue()
        {
            cur=t=NULL;
            sz=0;
        }
        bool empty()
        {
            if(t==NULL)
                return 1;
            return 0;
        }
        void push(string s)
        {
            ++sz;
            node *temp=new node;
            temp->s=s;
            if(t==NULL)
            {
                t=temp;
                cur=temp;
                temp->next=NULL;
            }
            else
            {
                cur->next=temp;
                cur=temp;
                cur->next=NULL;
            }
        }
        void pop()
        {
            --sz;
            if(t==NULL)
                exit(1);
            t=t->next;
        }
        string top()
        {
            if(t==NULL)
                exit(1);
            return (t->s);
        }
        int size()
        {
            return sz;
        }
};
class Stack
{
    private:
        node *t;
    public:
        Stack()
        {
            t=NULL;
        }
        bool empty()
        {
            if(t==NULL)
                return 1;
            return 0;
        }
        void push(string s)
        {
            node *temp=new node;
            temp->s=s;
            temp->next=t;
            t=temp;
        }
        void pop()
        {
            if(t==NULL)
                exit(1);
            t=(t->next);
        }
        string top()
        {
            if(t==NULL)
                exit(1);
            return (t->s);
        }
};
class linked_list
{
private:
    node *head;node *tail;
public:
    linked_list()
    {
        head=tail=NULL;
    }
    void insert(string s)
    {
        node *temp=new node;
        temp->next=NULL;
        temp->s=s;
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    node *Qsort(node *head)
    {
        if(head==NULL)
            return head;
        node *l=new node;node *lcur=l;
        node *r=new node;node *rcur=r;
        node *cur=head->next;
        while(cur!=NULL)
        {
            if((cur->s)<(head->s))
            {
                lcur->next=cur;
                lcur=cur;
            }
            else
            {
                rcur->next=cur;
                rcur=cur;
            }
            cur=cur->next;
        }
        lcur->next=NULL;rcur->next=NULL;
        head->next=Qsort(r->next);
        if((l->next)==NULL)
            return head;
        lcur=Qsort(l->next);
        cur=lcur;
        while((cur->next)!=NULL)cur=cur->next;
        cur->next=head;
        return lcur;
    }
    void qsort()
    {
        head=Qsort(head);
        node *cur=head;
        while((cur->next)!=NULL)
            cur=cur->next;
        tail=cur;
    }
    void qinsert(string s)
    {
        node *temp=new node;
        temp->s=s;
        if(head==NULL)
        {
            head=tail=temp;
            return;
        }
        if((temp->s)<(head->s))
        {
            temp->next=head;
            head=temp;
            cout<<"gello"<<endl;
            return;
        }
        if((temp->s)>=(tail->s))
        {
            tail->next=temp;
            tail=temp;
            tail->next=NULL;
            return;
        }
        node *cur=head;
        while(((cur->next)->s)<(temp->s))cur=cur->next;
        temp->next=cur->next;
        cur->next=temp;
    }
    void print()
    {
        node *cur=head;
        while(cur!=NULL)
        {
            cout<<(cur->s)<<"\n";
            cur=cur->next;
        }
    }
};
struct bnode
{
    string s;
    bnode *lc,*rc;
    bnode()
    {
        lc=rc=NULL;
    }
};
class bst
{
private:
    bnode *root;
public:
    bst()
    {
        root=NULL;
    }
    void insert(Queue q)
    {
        bnode *temp[q.size()];
        int stx=0;
        while(!q.empty())
        {
            string t=q.top();
            q.pop();
            temp[stx]=new bnode();
            temp[stx]->s=t;
            if(stx)
            {
                int p=(stx-1)>>1;
                if(stx&1)
                    temp[p]->lc=temp[stx];
                else
                    temp[p]->rc=temp[stx];
            }
            ++stx;
        }
        root=temp[0];
    }
    void Pre(bnode *r)
    {
        if(r==NULL)
            return;
        cout<<(r->s)<<"\n";
        Pre(r->lc);
        Pre(r->rc);
    }
    void preorder()
    {
        Pre(root);
    }
    void Post(bnode *r)
    {
        if(r==NULL)
            return;
        Post(r->lc);
        Post(r->rc);
        cout<<(r->s)<<"\n";
    }
    void postorder()
    {
        Post(root);
    }
    void in(linked_list &l,bnode *r)
    {
        if(r==NULL)
            return;
        in(l,r->lc);
        l.insert(r->s);
        in(l,r->rc);
    }
    void inorder(linked_list &l)
    {
        in(l,root);
    }
};
void getinput(Queue &q,string s)
{
  std::ifstream file(s);
  std::string str;
  while (getline(file,str))
  {
      q.push(str);
  }
}
void press()
{
    cout<<"Press any key to continue\n";
    getchar();
}
int main()
{
    Queue q;
    cout<<"queue"<<endl;
    getinput(q,"a.txt");
    Queue g;
    while(!q.empty())
    {
        string temp=q.top();
        q.pop();
        cout<<temp<<"\n";
        g.push(temp);
    }
    press();
    cout<<"Reversed Queue"<<endl;
    Stack s;
    while(!g.empty())
    {
        s.push(g.top());
        g.pop();
    }
    while(!s.empty())
    {
        g.push(s.top());
        s.pop();
    }
    while(!g.empty())
    {
        cout<<(g.top())<<"\n";
        q.push(g.top());
        g.pop();
    }
    press();
    cout<<"bst"<<endl;
    bst b;
    b.insert(q);
    cout<<"Preorder\n";
    b.preorder();
    press();

    
    cout<<"Postorder\n";
    b.postorder();
    press();
    cout<<"linked list"<<endl;
    linked_list l;
    b.inorder(l);
    l.print();
    press();
    cout<<"Sorted List\n";
    l.qsort();
    l.print();
    cout<<endl<<"Please enter entry\n";
    string ch;
    getline(cin,ch);
    cout<<"modified linked list"<<endl;
    l.qinsert(ch);
    l.print();
    press();
}
