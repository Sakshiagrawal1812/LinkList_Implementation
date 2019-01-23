#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
#define SUCCESS 1
#define FAILURE 0

typedef struct book_record_tag
{
   struct book_record_tag *next;
   struct book_record_tag *prv;
   int copies,year;
   char author[SIZE],book[SIZE];
} node;

node* insertion(int s);
int delete_record(char author[],char book[],int n,node*dptr);
int records(node*lptr);
int isEmpty(node *lptr);
int isFull(int num,int n);
void topMostBookAuthor(node *lptr,char book[]);
void MostPopularAuthor(node *ptr);
void k_th_popular(node *kptr,int n);
void least_popular(node *ptr1,int p,int k);
node* insert_unique(int m);
void unique_record(node *lptr);
void list_union(node *lptr1,node *lptr2);
void list_intersect(node *lptr1,node *lptr2);
void list_difference(node *lptr1,node *lptr2);
void list_symmetric(node *lptr1,node *lptr2);


int main()
{  node *lptr,*ptr,*gptr;
    int n,num,res,k,o,p,m,n1,n2;
    node *nptr,*kk,*l,*s;
    char *kptr;
    int s1,s2,l1,l2;
    node *ptr1,*ptr2,*ll1,*ll2;

   lptr=NULL;
   int c,y;
   char option;
   option='l';
   char author_name[SIZE],book_name[SIZE];
   int a;
   printf("enter the details of book record\n");
   while(option=='l')
   {

         	//ENTER THE VALUE
         	printf("choose the operation\n");
         	printf("=======================\n");
             printf("\n 1:insert book \n");
             printf("\n 2:delete book \n");
             printf("\n 3:active records \n");
             printf("\n 4:Is Empty \n");
             printf("\n 5:is full\n");
             printf("\n 6:getTopMostBookAuthor \n");
             printf("\n 7:most popular author \n");
             printf("\n 8:k_th popular author \n");
             printf("\n 9:least_popular author\n");
             printf("\n 10:unique record \n");
             printf("\n 11:list_union \n");
             printf("\n 12:list_intersection \n");
             printf("\n 13:list_difference \n");
             printf("\n 14:list_symmetric difference\n");
             printf("\nenter the choice \n");
             scanf("%d",&a);

        //SWITCH CASE STATEMENT
        switch(a)
       {
         case (1):
             lptr=NULL;

             printf("enter the num of records which u want to enter");
             scanf("%d",&n);
             lptr=insertion(n);
             nptr=lptr;
             printf("display the records:\n\n");
             while(nptr!=NULL)
             {
                 printf("author:%s\n",nptr->author);
                 printf("book:%s\n",nptr->book);
                 printf("year:%d\n",nptr->year);
                 printf("copies:%d\n\n\n\n\n",nptr->copies);
                 nptr=nptr->next;
             }
             break;

        case 2:

        	printf("enter the author name \n");
        	scanf("%s",author_name);
        	printf("enter the book name \n");
        	scanf("%s",book_name);
            res=delete_record(author_name,book_name,n,lptr);
            if(res==1)
            {
            	printf("deleted\n\n");

	        }
			else
			{
				printf("error\n\n");
			}
                break;

        case 3:

           num=records(lptr);
           printf("num of records:");
           printf("%d\n",num);
           break;


        case 4:

            res=isEmpty(lptr);
            if(res==1)
            {
                printf("record is empty\n");

            }
            else{
                printf("record is not empty\n");
            }
            break;


        case 5:
            res=isFull(num,n);
            if(res==1)
            {
                printf("record is full\n");
            }
            else{
                printf("record is not full\n");
            }
            break;


        case 6:
            printf("enter the book name:");
            scanf("%s",book_name);
            topMostBookAuthor(lptr,book_name);
            break;

        case 7:
            MostPopularAuthor(lptr);
            break;

        case 8:

            printf("enter the value of k:");
            scanf("%d",&k);
            k_th_popular(lptr,k);

            break;


        case 9:
            printf("enter the value of p:");
            scanf("%d",&p);
            printf("enter the value of k:");
            scanf("%d",&o);
            least_popular(lptr,p,o);
            break;



        case 10:

            printf("enter the num of nodes:");
            scanf("%d",&m);
            ptr=insert_unique(m);
            kk=ptr;
            printf("=====================");
            printf("\n\n\nrecord is:\n\n\n");
            while(kk!=NULL)
            {
                printf("author:%s\n",kk->author);
                printf("book:%s\n",kk->book);
                printf("year:%d\n",kk->year);
                printf("copies:%d\n\n\n\n\n",kk->copies);
                kk=kk->next;
            }
            unique_record(ptr);
            break;

        case 11:

            printf("enter the num of nodes of list 1:");
            scanf("%d",&n1);
            printf("enter the num of nodes of list 2:");
            scanf("%d",&n2);
            l=insertion(n1);
            s=insertion(n2);
            list_union(l,s);
            break;

        case 12:

            printf("enter the num of nodes of list 1:");
            scanf("%d",&s1);
            printf("enter the num of nodes of list 2:");
            scanf("%d",&s2);
            ptr1=insertion(s1);
            ptr2=insertion(s2);
            list_intersect(ptr1,ptr2);
            break;

        case 13:

            printf("enter the num of nodes of list 1:");
            scanf("%d",&l1);
            printf("enter the num of nodes of list 2:");
            scanf("%d",&l2);
            ll1=insertion(l1);
            ll2=insertion(l2);
            list_difference(ll1,ll2);
            break;

        case 14:

            printf("enter the num of nodes of list 1:");
            scanf("%d",&l1);
            printf("enter the num of nodes of list 2:");
            scanf("%d",&l2);
            ll1=insertion(l1);
            ll2=insertion(l2);
            list_symmetric(ll1,ll2);
            break;


    }//switch case

   }//while
  return(0);
}


//insertion of book records
node* insertion(int s)
{
	int c,y;
	int flag=0;
    char author_name[SIZE],book_name[SIZE];
	node *lptr,*nptr,*sptr,*n0;
	nptr=NULL;
	lptr=NULL;
	int i;
	printf("enter the record details \n");

	    lptr=(node*) malloc(sizeof(node));
		printf("author name:");
        scanf("%s",author_name);
		strcpy(lptr->author,author_name);
		printf("book name:");
		scanf("%s",book_name);
		strcpy(lptr->book,book_name);
		printf("year:");
		scanf("%d",&y);
		lptr->year=y;
		printf("available copies:");
		scanf("%d",&c);
		lptr->copies=c;
		lptr->next=nptr;
		nptr=lptr;
		printf("success\n\n\n\n\n");
	for(i=1;i<s;i++)
	{
	    flag=0;
		node *temp=(node*) malloc(sizeof(node));
		printf("author name:");
        scanf("%s",author_name);
        strcpy(temp->author,author_name);
		printf("book name:");
		scanf("%s",book_name);
		strcpy(temp->book,book_name);
		printf("year:");
		scanf("%d",&y);
		temp->year=y;
		printf("available copies:");
		scanf("%d",&c);
		temp->copies=c;

      if(lptr->next==NULL)
      {
        if(strcmp(temp->author,lptr->author)<0)
     {

         temp->next=lptr;
         lptr=temp;
		 sptr=lptr;
		 printf("success\n\n\n\n\n");
		 flag=1;
     }
     else if(strcmp(temp->author,nptr->author)>0)
     {
         nptr=lptr;
        nptr->next=temp;
        nptr=temp;
	    nptr->next=NULL;
		printf("success\n\n\n\n\n");
		flag=1;

     }


    else
    {
             if(strcmp(temp->book,lptr->book)<0)
             {
                 temp->next=lptr;
                 nptr=lptr;
                 lptr=temp;
                 printf("success\n\n\n\n\n");
                 flag=1;
             }
             else if(strcmp(temp->book,lptr->book)>0)
                 {
                     lptr->next=temp;
                     temp->next=NULL;
                     printf("success\n\n\n\n\n");
                     flag=1;

                 }
            else
            {
                     lptr->copies=temp->copies;
                     lptr->year=temp->year;
                     printf("success\n\n\n\n");
                     flag=1;

            }
           }
       }
    else{

     if(flag==0 && strcmp(temp->author,lptr->author)<0)
     {

         temp->next=lptr;
         lptr=temp;
		 sptr=lptr;
		 printf("success\n\n\n\n\n");
		 flag=1;
     }
     else if(flag==0 && strcmp(temp->author,nptr->author)>0)
     {
        nptr->next=temp;
        nptr=temp;
	    nptr->next=NULL;
		printf("success\n\n\n\n\n");
		flag=1;

     }

     else if(flag==0 && lptr->next==nptr && strcmp(lptr->author,temp->author)==0)
     {
         if(strcmp(lptr->book,temp->book)<0)
                {
                    temp->next=lptr->next;
                    lptr->next=temp;
                    printf("success\n\n\n\n\n");
                    flag=1;
                }
                else if(strcmp(lptr->book,temp->book)>0)
                {
                    temp->next=lptr;
                    lptr=temp;
                    printf("success\n\n\n\n\n");
                    flag=1;

                }
                else
                {
                    lptr->copies=temp->copies;
                    lptr->year=temp->year;
                    printf("success\n\n\n\n\n");
                    flag=1;
                }
     }
     else if(flag==0 && strcmp(lptr->author,temp->author)!=0){
            node *prev=lptr;
            while(prev!=NULL && (strcmp(temp->author,prev->author))>0)
            {
                n0=prev;
                prev=prev->next;
            }
            if(strcmp(prev->author,temp->author)!=0){
            temp->next=prev->next;
            prev->next=temp;
            printf("success\n\n\n\n\n");
            flag=1;}
            else
            {
                if(flag==0 && strcmp(prev->book,temp->book)<0)
                {
                    temp->next=prev->next;
                    prev->next=temp;
                    printf("success\n\n\n\n\n");
                    flag=1;
                }
                else if(flag==0 && strcmp(prev->book,temp->book)>0)
                {
                    temp->next=prev;
                    n0->next=temp;
                    prev=temp;
                    printf("success\n\n\n\n\n");
                    flag=1;

                }
                else
                {
                    prev->copies=temp->copies;
                    prev->year=temp->year;
                    printf("success\n\n\n\n\n");
                    flag=1;
                }
            }

        }
     }


	}//for
	return lptr;

}//insert function

//delete function

int delete_record(char author[],char book[],int n,node *dptr)
{
	int i,ret,found=0;
	node *ptr;
	ptr=dptr;
	node *prev=NULL;
	while(dptr!=NULL && found==0)
    {

	  if(strcmp(dptr->author,author)==0 && strcmp(dptr->book,book)==0)
	  {
		found=1;

	   }
	   else{
        prev=dptr;
        dptr=dptr->next;

	   }
    }
	if(found==0)
	{
		ret= FAILURE;

	}
	else
	{
		prev->next=dptr->next;
        ptr=dptr;
        dptr=dptr->next;
		free(ptr);
		ret= SUCCESS;
	}
	return ret;

}

//num of records
int records(node *lptr)
{

    node *rptr;
    rptr=lptr;
    int count=0;
    while(rptr!=NULL)
    {
        count=count+1;
        rptr=rptr->next;
    }
    return count;
}

//is empty
int isEmpty(node *lptr)
{
    int ret;
    if(lptr==NULL)
    {
        ret=SUCCESS;
    }
    else
    {
        ret=FAILURE;
    }
    return ret;
}
//is full
int isFull(int count,int n)
{
    int ret;

    if(count==n)
    {
        ret=SUCCESS;
    }
    else{
        ret=FAILURE;
    }
    return ret;
}

//get TopMostBookAuthor
void topMostBookAuthor(node *bptr,char book[])
{
    node *fptr;
    int done=0;
    while(bptr!=NULL && done==0)
    {
        if(strcmp(book,bptr->book)==0)
        {
             fptr=bptr;
             done=1;

        }
        else
        {
            bptr=bptr->next;
        }
    }
    int c=0;
    if(done==0)
    {
        printf("the book which u enter is not present in the records\n");
    }
    else{
        bptr=bptr->next;
        while(bptr!=NULL)
        {
            if((strcmp(bptr->book,book))==0)
            {
                if((bptr->copies)> (fptr->copies))
                {
                    fptr=bptr;
                    bptr=bptr->next;
                }
            }
            else{
                bptr=bptr->next;
            }
        }
        printf("top most book author is :%s\n\n",fptr->author);
    }

}


//most popular author
void MostPopularAuthor(node *ptr)
{
    node *mptr,*nptr;
    node *fptr;
    int hl=0,done=1,i;
    nptr=ptr;
    mptr=ptr->next;
    while(nptr!=NULL)
    {
        while(mptr!=NULL && strcmp(ptr->author,mptr->author)==0)
        {
            ptr->copies=ptr->copies + mptr->copies;
            ptr=ptr->next;
            mptr=mptr->next;
        }
        if(ptr->copies > hl)
        {
               fptr=ptr;
               hl=ptr->copies;
               nptr=nptr->next;
               ptr=ptr->next;
               if(mptr!=NULL){
               mptr=ptr->next;}
        }
    }
    printf("author is %s\n\n",fptr->author);
    printf("copies:%d\n\n",hl);

}


//k th popular book
void k_th_popular(node *lptr,int k)
{
    node *ptr=lptr;
    char temp[20]="\0";
    char tempf[20]="\0";
    int done=0,i=k,cf=500;
    int cm,c;
    node *n;
    while(i>0)
    {
        cm=0; ptr=lptr;
        while(ptr!=NULL)
        { if(strcmp(ptr->author,tempf)!=0)
           {n=ptr->next;
           c=ptr->copies;
           while(n!=NULL && strcmp(n->book,ptr->book)==0)
           {
               c=c+n->copies;
               n=n->next;
           }
           if(c>cm && c<cf)
           {
               cm=c;
               strcpy(temp,ptr->author);
           }
           ptr=n;
        }
        else{ ptr=ptr->next;}
        }
        cf=cm;
        strcpy(tempf,temp);
        i--;
    }



    printf("\n\n%d popular book author is %s \n\n",k,tempf);
}


//least popular
void least_popular(node *ptr1,int p,int k)
{
    node *ptr2,*p1,*p2;
    int m,h,done=0;
    ptr2=ptr1->next;
    p1=ptr1;
    p2=ptr2;
    if(ptr1==NULL)
    {
        printf("record is empty\n");
    }
    else
    {
        while(ptr2!=NULL)
        {
            while(p2!=NULL && strcmp(p1->author,p2->author)==0 )
            {
                p1->copies=p1->copies+p2->copies;
                p2=p2->next;
            }
            h=ptr1->copies+ptr2->copies;
            if(h < p)
                {
                    m=(h*100)/p1->copies;
                    if(m>k)
                    {
                    printf("least popular author:%s\n\n\n",ptr1->author);
                    done=1;}
                    else{
                        printf("no author!!!");
                    }
                }

                ptr1=p2;
                if(p2!=NULL){p2=p2->next;
                ptr2=ptr1->next;}
                else{ptr2=NULL;}
                p1=ptr1;

            }
            if(done==0)
            {
                printf("no author...!!!\n\n\n\n");
            }
        }
}

//unique record

//insert function for unique

node* insert_unique(int s)
{
    int c,y;
	int flag=0;
    char author_name[SIZE],book_name[SIZE];
	node *lptr,*nptr,*sptr,*n0;
	nptr=NULL;
	lptr=NULL;
	int i;
	printf("enter the record details \n");

	    lptr=(node*) malloc(sizeof(node));
		printf("author name:");
        scanf("%s",author_name);
		strcpy(lptr->author,author_name);
		printf("book name:");
		scanf("%s",book_name);
		strcpy(lptr->book,book_name);
		printf("year:");
		scanf("%d",&y);
		lptr->year=y;
		printf("available copies:");
		scanf("%d",&c);
		lptr->copies=c;
		lptr->next=nptr;
		nptr=lptr;
		printf("success\n\n\n\n\n");
	for(i=1;i<s;i++)
	{
	    flag=0;
		node *temp=(node*) malloc(sizeof(node));
		printf("author name:");
        scanf("%s",author_name);
        strcpy(temp->author,author_name);
		printf("book name:");
		scanf("%s",book_name);
		strcpy(temp->book,book_name);
		printf("year:");
		scanf("%d",&y);
		temp->year=y;
		printf("available copies:");
		scanf("%d",&c);
		temp->copies=c;

      if(lptr->next==NULL)
      {
        if(strcmp(temp->author,lptr->author)<0)
     {

         temp->next=lptr;
         lptr=temp;
		 sptr=lptr;
		 printf("success\n\n\n\n\n");
		 flag=1;
     }
     else if(strcmp(temp->author,nptr->author)>0)
     {
         nptr=lptr;
        temp->next=nptr->next;
        nptr->next=temp;
        nptr=temp;
	printf("success\n\n\n\n\n");
		flag=1;

     }
     else
           {
             if(strcmp(temp->book,lptr->book)<=0)
             {
                 temp->next=lptr;
                 lptr=temp;
                 printf("success\n\n\n\n\n");
                 flag=1;
             }
             else
                 {
                     sptr=lptr;
                     temp->next=sptr->next;
                     sptr->next=temp;
                     printf("success\n\n\n\n\n");
                     flag=1;

                 }

           }
       }
    else{

     if(flag==0 && strcmp(temp->author,lptr->author)<0)
     {

         temp->next=lptr;
         lptr=temp;
		 sptr=lptr;
		 printf("success\n\n\n\n\n");
		 flag=1;
     }
     else if(flag==0 && strcmp(temp->author,nptr->author)>0)
     {
        nptr->next=temp;
        nptr=temp;
	    nptr->next=NULL;
		printf("success\n\n\n\n\n");
		flag=1;

     }

     else if(flag==0 && lptr->next==nptr && strcmp(lptr->author,temp->author)==0)
     {
         if(strcmp(lptr->book,temp->book)<=0)
                {
                    temp->next=lptr->next;
                    lptr->next=temp;
                    printf("success\n\n\n\n\n");
                    flag=1;
                }
                else if(strcmp(lptr->book,temp->book)>0)
                {
                    temp->next=lptr;
                    lptr=temp;
                    printf("success\n\n\n\n\n");
                    flag=1;

                }

     }
     else if(flag==0 && strcmp(lptr->author,temp->author)!=0){
            node *prev=lptr;
            while(prev!=NULL && (strcmp(temp->author,prev->author))>0)
            {
                n0=prev;
                prev=prev->next;
            }
            if(strcmp(prev->author,temp->author)!=0){
            temp->next=prev->next;
            prev->next=temp;
            printf("success\n\n\n\n\n");
            flag=1;}
            else
            {
                if(flag==0 && strcmp(prev->book,temp->book)<=0)
                {
                    temp->next=prev->next;
                    prev->next=temp;
                    printf("success\n\n\n\n\n");
                    flag=1;
                }
                else
                {
                    temp->next=prev->next;
                    n0->next=temp;
                    prev=temp;
                    printf("success\n\n\n\n\n");
                    flag=1;

                }
            }

        }
     }


  }//for
  return lptr;
}
//function definition
void unique_record(node *lptr)
{
    node *prev,*ptr,*xptr,*lptr1,*head;
    int done=0;
    lptr1=lptr;
    prev=NULL;
    head=lptr;
    ptr=lptr->next;
    if(lptr==NULL)
    {
       printf("node is not present\n\n");
    }
    else if(lptr->next==NULL)
    {
       printf("single node is present:%s\n\n",lptr->author);
    }

    else{


    	if((strcmp(lptr->author,ptr->author)==0) && (strcmp(lptr->book,ptr->book)==0))
        {
            if((lptr->year) > (ptr->year))
            {
               xptr=ptr;
               lptr->next=ptr->next;
               ptr=ptr->next;
               free(xptr);
               head=lptr;


            }
            else
            {
                xptr=lptr;
                lptr=lptr->next;
                ptr=lptr->next;
                free(xptr);
                head=lptr;

            }
        }
        else
        {
           head=lptr;
           prev=lptr;
           lptr=ptr;
           ptr=lptr->next;
        }

       lptr1=head;
       while(ptr!=NULL && done==0)
       {
        if((strcmp(lptr->author,ptr->author)==0) && (strcmp(lptr->book,ptr->book)==0))
        {
            if((lptr->year) > (ptr->year))
            {
               xptr=ptr;
               lptr->next=ptr->next;
               ptr=lptr->next;
               free(xptr);
               done=1;

            }
            else
            {
                xptr=lptr;
                lptr=lptr->next;
                prev=lptr->prv;
                if(ptr!=NULL){
                ptr=lptr->next;}
                free(xptr);
                done=1;

            }
        }
        else
        {

           lptr=lptr->next;
           prev=lptr->prv;
           ptr=lptr->next;
        }
    }
   }
    printf("after removing the duplicate copies:\n");
    printf("new book record is:\n\n\n");
    while(head!=NULL)
    {
        printf("author:%s\n",head->author);
        printf("book:%s\n",head->book);
        printf("year:%d\n",head->year);
        printf("copies:%d\n\n\n\n\n",head->copies);
        head=head->next;
    }
}



//list union
void list_union(node *lptr1,node *lptr2)
{
    node *list3,*r;
    node *p,*q,*p1,*q1;
    p=lptr1;
    q=lptr2;
    if(p==NULL)
    {
        list3=lptr2;
    }
    else if(q==NULL)
     {
        list3=lptr1;

     }
    else
    {
        if(strcmp(p->author,q->author)<0)
        {
            list3=p;
            p=p->next;
        }
        else if(strcmp(p->author,q->author)>0)
        {
            list3=q;
            q=q->next;
        }
        else
        {
            if(strcmp(p->book,q->book)<0)
            {
                list3=p;
                p=p->next;
            }
            else if(strcmp(p->book,q->book)>0)
            {
                list3=q;
                q=q->next;
            }
            else
            {
                if(p->year > q->year)
                {
                    list3=p;
                    p=p->next;
                    q1=q;
                    q=q->next;
                    free(q1);
                }
                else
                {
                    list3=q;
                    q=q->next;
                    p1=p;
                    p=p->next;
                    free(p1);
                }
            }
        }
    }
    r=list3;
    while((p!=NULL) && (q!=NULL))
    {
        if(strcmp(p->author,q->author)<0)
        {
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else if(strcmp(p->author,q->author)>0)
        {
            r->next=q;
            q=q->next;
            r=r->next;
        }
        else
        {
            if(strcmp(p->book,q->book)<0)
            {
                r->next=p;
                p=p->next;
                r=r->next;
            }
            else if(strcmp(p->book,q->book)>0)
            {
                r->next=q;
                q=q->next;
                r=r->next;

            }
            else
            {
                if(p->year > q->year)
                {
                    r->next=p;
                    p=p->next;
                    r=r->next;
                    q1=q;
                    free(q1);

                }
                else
                {
                    r->next=q;
                    q=q->next;
                    r=r->next;
                    p1=p;
                    free(p1);
                }
            }
        }//else
    if(p!=NULL)
    {
        r->next=p;
    }
    else if(q!=NULL)
    {
        r->next=q;
    }
  }//while
  printf("union merge list:\n\n");
  while(list3!=NULL)
  {
        printf("author:%s\n",list3->author);
        printf("book:%s\n",list3->book);
        printf("year:%d\n",list3->year);
        printf("copies:%d\n\n\n\n\n",list3->copies);
        list3=list3->next;
  }
}//list union


void list_intersect(node *lptr1,node *lptr2)
{
    node *list3,*r;
    node *p,*q,*p1,*q1,*ptr1,*ptr2;
    p=lptr1;
    q=lptr2;
    ptr1=lptr1;
    ptr2=lptr2;
    if(p==NULL)
    {
        printf("list 3 is empty\n");
    }
    else if(q==NULL)
    {
        printf("list 3 is empty\n");
    }
        while(ptr2!=NULL)
        {
            if(strcmp(ptr1->author,ptr2->author)==0 && strcmp(ptr1->book,ptr2->book)==0)
            {
                if(ptr1->copies < ptr2->copies)
                {
                    list3=ptr1;
                    ptr1=ptr1->next;
                }
                else
                {
                    list3=ptr2;
                    ptr2=ptr2->next;
                }
            }
            else
            {
                ptr2=ptr2->next;
            }
        }
        list3->next=NULL;
        r=list3;
        ptr1=ptr1->next;
        ptr2=lptr2;
    while(ptr1!=NULL)
    {
        ptr2=lptr2;
        while(ptr2!=NULL)
        {
            if(strcmp(ptr1->author,ptr2->author)==0 && strcmp(ptr1->book,ptr2->book)==0)
            {
                if(ptr1->copies < ptr2->copies)
                {
                    r->next=ptr1;
                    r=r->next;
                }
                else
                {
                    r->next=ptr2;
                    r=r->next;
                }
            }
            else
            {
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }

    printf("intersection of list 1 and list 2 is :\n\n");
    while(list3!=NULL)
    {
        printf("author:%s\n",list3->author);
        printf("book:%s\n",list3->book);
        printf("year:%d\n",list3->year);
        printf("copies:%d\n\n\n\n\n",list3->copies);
        list3=list3->next;
    }
}


//list_difference
void list_difference(node *lptr1,node *lptr2)
{
    node *list3,*r=NULL;
    node *ptr1,*ptr2;
    ptr1=lptr1;
    ptr2=lptr2;
    int done=1;
    while(ptr1!=NULL)
    {
        done=1;
        while(ptr2!=NULL && done==1)
        {
            if(strcmp(ptr1->author,ptr2->author)==0 )
            {
                if(strcmp(ptr1->book,ptr2->book)!=0)
                {
                    list3=ptr1;
                    list3->next=r;
                    r=list3;
                    ptr2=ptr2->next;
                }
                else
                {
                    done=0;
                    ptr2=ptr2->next;
                }
            }
            else{
                list3=ptr1;
                list3->next=r;
                r=list3;
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
    printf("list difference:\n");
    while(list3!=NULL)
    {
        printf("author:%s\n",list3->author);
        printf("book:%s\n",list3->book);
        printf("year:%d\n",list3->year);
        printf("copies:%d\n\n\n\n\n",list3->copies);
        list3=list3->next;
    }
}


//list symmetric difference
void list_symmetric(node *lptr1,node *lptr2)
{
    node *list3,*r,*p,*q,*p1,*q1;
    list3=NULL;
    p=lptr1;
    q=lptr2;
    if(p==NULL)
    {
        list3=lptr2;
    }
    else if(q==NULL)
     {
        list3=lptr1;

     }
    else
    {
      while(p!=NULL && q!=NULL && list3==NULL)
      {
        if(strcmp(p->author,q->author)<0)
        {
            list3=p;
            p=p->next;
        }
        else if(strcmp(p->author,q->author)>0)
        {
            list3=q;
            q=q->next;
        }
        else
        {
            if(strcmp(p->book,q->book)<0)
            {
                list3=p;
                p=p->next;
            }
            else if(strcmp(p->book,q->book)>0)
            {
                list3=q;
                q=q->next;
            }
            else
            {

                    q1=q;
                    q=q->next;
                    free(q1);
                    p1=p;
                    p=p->next;
                    free(p1);

            }
        }
      }
    }
    r=list3;
    while((p!=NULL) && (q!=NULL))
    {
        if(strcmp(p->author,q->author)<0)
        {
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else if(strcmp(p->author,q->author)>0)
        {
            r->next=q;
            q=q->next;
            r=r->next;
        }
        else
        {
            if(strcmp(p->book,q->book)<0)
            {
                r->next=p;
                p=p->next;
                r=r->next;
            }
            else if(strcmp(p->book,q->book)>0)
            {
                r->next=q;
                q=q->next;
                r=r->next;

            }
            else
            {
                    p1=p;
                    p=p->next;
                    q1=q;
                    q=q->next;
                    free(p1);
                    free(q1);
            }
        }//else
    }//while
    if(p!=NULL)
    {
        while(p!=NULL)
        {
           r->next=p;
           p=p->next;
        }
    }
    else if(q!=NULL)
    {
        while(q!=NULL)
        {
           r->next=q;
           q=q->next;
        }
    }
  printf("list symmetric difference:\n\n");
  while(list3!=NULL)
  {
        printf("author:%s\n",list3->author);
        printf("book:%s\n",list3->book);
        printf("year:%d\n",list3->year);
        printf("copies:%d\n\n\n\n\n",list3->copies);
        list3=list3->next;
  }

}
