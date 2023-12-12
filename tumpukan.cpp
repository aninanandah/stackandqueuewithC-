#include <iostream>

using namespace std;

class stack
{
   public:
   int *tumpukan;
   int ukuran;
   int top;
   void insert(int i);
   void take();
   void clear();
   void find(int i);
   void display();

   stack(int i)
   {
   	ukuran=i;
      tumpukan=new int[ukuran];
      top=0;
   }

private:
   int isempty();
   int fully();
};


int stack::isempty()
{
    if(top<=0)
       return 1;
    else
       return 0;
}

int stack::fully()
{
   if(top>=ukuran)
   	return 1;
   else
      return 0;
}


void stack::insert(int i)
{
   if(fully()==1)
   {
     cout<<"maaf tumpukan penuh"<<endl;
   }else
   {
     cout<<"Nilai "<<i<<" masuk ke tumpukan"<<endl;
     tumpukan[top++]=i;
   }
}

void stack::find(int i)
{
    int temp=0;
    int hasil=0;
    while(temp<top)
    {
       if(i==tumpukan[temp])
       {
          hasil=1;
          break;
       }
       temp++;
    }

    if(hasil==1)
    {
       cout<<"Nilai "<<i<<" ditemukan ditumpukan ke "<<(temp+1)<<endl;
    }else
    {
       cout<<"tumpukan tidak ditemukan"<<endl;
    }
}

void stack::take()
{
    if(isempty()==1)
    {
       cout<<"Maaf, tumpukan kosong"<<endl;
    }else
    {
       int pop=tumpukan[--top];
       cout<<"Nilai "<<pop<<" keluar tumpukan"<<endl;
    }
}

void stack::clear()
{
   cout<<"stack telah dikosongkan"<<endl;
   top=0;
   display();
}

void stack::display()
{
   if(isempty()==0)
   {
	   cout<<"Isi Tumpukan :"<<endl;
      int x=top;
      while(x>0)
      {
         cout<<"tumpukan ke :["<<(x)<<"] :"<<tumpukan[x-1]<<endl;
         x--;
      }
   }else
   {
     cout<<"maaf tumpukan kosong"<<endl;
   }
}

main()
{
	int ukuran;
   char pilih;
   cout<<"Program stack/tumpukan"<<endl;
   cout<<"Masukkan jumlah tumpukan :";
   cin>>ukuran;
   cout<<"Pilih program"<<endl;
   cout<<"1. Insert"<<endl;
   cout<<"2. take"<<endl;
   cout<<"3. find"<<endl;
   cout<<"4. clear"<<endl;
   cout<<"5. exit"<<endl;

   stack *s;
   s=new stack(ukuran);

   do
   {
         cout<<endl;
         cout<<"Pilihan :";
         cin>>pilih;

         switch(pilih)
         {
         	case '1':
               int c;
               cout<<"Masukkan angka:";
               cin>>c;
               s->insert(c);
               s->display();
               break;
            case '2':
              s->take();
              s->display();
              break;
            case '3':
              int k;
              cout<<"Masukkan angka yang dicari :";
              cin>>k;
              s->find(k);
              s->display();
              break;
            case '4':
              s->clear();
              s->display();
              break;
            default:
               cout<<"Angka yang anda masukkan salah atau anda telah keluar "<<endl;
         }
   }while(pilih!='5');
 	delete s->tumpukan;

}


