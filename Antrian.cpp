#include <iostream>
using namespace std;


class queue
{
    public:
       int *antrian;
       int ukuran;
       int top;
       void insert(int i);
       void pop();
       void find(int i);
       void display();

    queue(int i)		//// constructor
    {
       ukuran=i;
       antrian=new int[ukuran];
       top=0;
    }

    private:
    int isempty();
    int fully();
};

int queue::isempty()
{
   if(top<=0)
     return 1;
   else
     return 0;
}

int queue::fully()
{
   if(top>=ukuran)
     return 1;
   else
     return 0;
}

void queue::insert(int i)
{
  if(fully()==1)
  {
    cout<<"maaf antrian penuh"<<endl;
  }else
  {
    cout<<"nilai "<<i<<" masuk antrian"<<endl;
    antrian[top++]=i;
  }
}

void queue::pop()
{
   if(isempty()==1)
   {
     cout<<"maaf, antrian kosong"<<endl;
   }else
   {
     int pop=antrian[0];
     int i=1;
     cout<<"nilai "<<pop<<" keluar antrian"<<endl;
     while(i<top)
     {
       antrian[i-1]=antrian[i];
       i++;
     }
     top--;
   }
}

void queue::find(int i)
{
   int temp=0;
   int hasil=0;
   while(temp<top)
   {
      if(i==antrian[temp])
      {
         hasil=1;
         break;
      }
      temp++;
   }

   if(hasil==1)
   {
     cout<<"Nilai "<<i<<" ditemukan diantrian ke "<<(temp+1)<<endl;
   }else
   {
     cout<<"antrian tidak ditemukan"<<endl;
   }
}

void queue::display()
{
   cout<<"Isi antrian :"<<endl;
   int i=0;
   while(i<top)
   {
      cout<<"antrian ke :["<<(i+1)<<"] :"<<antrian[i]<<endl;
      i++;
   }
}

main()
{
    int ukuran;
    char pilih;
    cout<<"Program queue/antrian"<<endl;
    cout<<endl;
    cout<<"Masukkan jumlah antrian :";
    cin>>ukuran;
    cout<<"Pilih program"<<endl;
    cout<<"1. Insert"<<endl;
    cout<<"2. pop"<<endl;
    cout<<"3. find"<<endl;
    cout<<"4. Display"<<endl;
    cout<<"5. Exit"<<endl;

    queue *q;
    q=new queue(ukuran);

    do
    {
        cout<<"Pilihan :";
        cin>>pilih;

        switch(pilih)
        {
            case '1':
                int c;
                cout<<"Masukkan angka :";
                cin>>c;
                q->insert(c);
                break;
            case '2':
              q->pop();
              break;
            case '3':
                int k;
                cout<<"Masukkan angka yang dicari :";
                cin>>k;
                q->find(k);
                break;
            case '4':
                q->display();
                break;
            default:
         cout<<"Angka yang anda masukkan salah atau anda telah keluar "<<endl;
        }
    }while(pilih!='5');
    	delete q->antrian;

}



