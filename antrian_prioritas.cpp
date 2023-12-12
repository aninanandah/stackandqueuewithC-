#include<iostream>

using namespace std;

class PQ
{
   public:
      int *priority;
      int ukuran;
      int top;
      void insert(int i);
      void pop();
      void display();

      PQ(int i)
      {
         ukuran=i;
         priority=new int[ukuran];
         top=0;
      }

      private:
       int isempty();
       int fully();
};

int PQ::isempty()
{
   if(top<=0)
      return 1;
   else
      return 0;
}

int PQ::fully()
{
   if(top>=ukuran)
       return 1;
   else
       return 0;
}

void PQ::pop()
{
   if(isempty()==1)
   {
     cout<<"maaf, antrian kosong"<<endl;
   }else
   {
     int pop=priority[0];
     int i=1;
     cout<<"nilai "<<pop<<" keluar antrian"<<endl;
     while(i<top)
     {
       priority[i-1]=priority[i];
       i++;
     }
     top--;
   }
}

void PQ::display()
{
   cout<<"Isi antrian :"<<endl;
   int i=0;
   while(i<top)
   {
      cout<<"antrian ke :["<<(i+1)<<"] :"<<priority[i]<<endl;
      i++;
   }
}


void PQ::insert(int k)
{
   if(fully()==1)
   {
      cout<<"maaf antrian berprioritas penuh"<<endl;
   }else
   {
    if(isempty()==1)
    {
       cout<<"nilai "<<k<<" masuk antrian"<<endl;
       priority[top++]=k;
    }else
    {
     int i;
     for(i=0;i<top;i++)
     {
      	      if(k<priority[i])
             {
               break;
             }
      }

      for(int j=top;j>i;j--)
      {
     	      priority[j]=priority[j-1];
      }
      priority[i]=k;
      top++;
     cout<<"nilai "<<k<<" masuk antrian"<<endl;
     }
   }
}

main()
{
    int ukuran;
    char pilih;
    cout<<"Program priorty queue/antrian berprioritas"<<endl;
    cout<<endl;
    cout<<"Masukkan jumlah antrian :";
    cin>>ukuran;
    cout<<"Pilih program"<<endl;
    cout<<"1. Insert"<<endl;
    cout<<"2. pop"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Exit"<<endl;

    PQ *pq;
    pq=new PQ(ukuran);

    do
    {
        cout<<endl;
        cout<<"Pilihan :";
        cin>>pilih;

        switch(pilih)
        {

            case '1':
                int c;
                cout<<"Masukkan angka :";
                cin>>c;
                pq->insert(c);
                break;
            case '2':
                pq->pop();
                break;
            case '3':
                pq->display();
                break;
            default:
               cout<<"Angka yang anda masukkan salah atau anda telah keluar "<<endl;
        }
    }while(pilih!='4');
     delete pq->priority;

}
