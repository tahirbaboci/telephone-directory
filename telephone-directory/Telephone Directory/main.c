#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct
{
    long int telNo;
    long int kod;
    char isim[20];

} rehber;

void KayitEkle();
void KayitListele();
void KaydiDuzenle();
void NoBul();
void IsimBul();
void KayitSil();

int main()
{


    int  secim;
    setlocale(LC_ALL, "Turkish");
    printf("\t\t TELEFON REHBERI V1.0 \n");
    printf("\t\t ******************** \n");
    printf("Islemler : \n");
    printf("1.Kayit Ekle \n");
    printf("2.Telefonlari Listele \n");
    printf("3.Kaydi Duzenle \n");
    printf("4.Numara Ile Kayit Bul \n");
    printf("5.Isim Ile Kayit Bul \n");
    printf("6.Kayit Sil\n");
    printf("0.Cikis \n\n");
    printf("---------------------\n\n");
    printf("Secim : ");
    scanf("%d",&secim);
    switch(secim)
    {
    case 01 :
        KayitEkle();
        break;
    case 2 :
        KayitListele();
        break;
    case 3 :
        KaydiDuzenle();
        break;
    case 4:
        NoBul();
        break;
    case 5 :
        IsimBul();
        break;
    case 6 :
        KayitSil();
        break;
    case 0 :

        return 0;

    default:
        printf("Yanlis Bir Seçim Yaptiniz.");

        break;
    }
    return 0 ;

}
void KayitEkle()
{
system("cls");
    char devam='e';

        rehber eleman;

        FILE *fp;
        fp=fopen("TelefonRehber.txt","a");
        printf("TelNo Giriniz : ");
        scanf("%Id",&eleman.telNo);
        printf("Kod Giriniz : ");
        scanf("%Id",&eleman.kod);
        printf("Isim Giriniz : ");
        scanf("%s",eleman.isim);
        fwrite(&eleman,sizeof(rehber),1,fp);
        fclose(fp);

 printf("Ýþleme Devam Etmek Ýstermisiniz <e/h>");
scanf("%s",&devam);
 if ((devam == 'E') || (devam == 'e'))
            KayitEkle();
            else
                main();






}
void KayitListele()
{
    system("cls");
    char temp,devam='e';
    rehber kayit;
    FILE *fp;
    fp=fopen("TelefonRehber.txt","r");

    while(fread(&kayit,sizeof(rehber),1,fp)==1)
    {
        printf("Ad    : %s \n ",kayit.isim);
        printf("Tel No: %Id \n ",kayit.telNo);
        printf("Kod   : %Id \n \n",kayit.kod);

    }


    fclose(fp);
          printf("Isleme Devam Etmek Ýstermisiniz <e/h>");
      scanf("%s",&devam);
 if ((devam == 'E') || (devam == 'e'))
            KayitListele();
            else
                main();



}
void KaydiDuzenle()
{

    system("cls");
    char aranacak[100];
    rehber *kayitlar;
    rehber kayit;
    kayitlar=(rehber*) malloc(sizeof(rehber));
    char devam='e';
    FILE *Dosya;


        Dosya=fopen("TelefonRehber.txt","r");
        kayitlar=(rehber*) malloc(sizeof(rehber));

        int i=0,sayi;
        while(fread(&kayit,sizeof(rehber),1,Dosya)==1)
        {
            kayitlar= (rehber*) realloc(kayitlar,sizeof(rehber)*(i+1));
            *(kayitlar+i)=kayit;
            i++;
        }
        sayi=i;
        fclose(Dosya);
        printf("Düzenlenecek kisinin adini giriniz : ");
        scanf("%s",aranacak);
        for(i=0; i<sayi; i++)
            if(strcmp(kayitlar[i].isim,aranacak)==0)
                break;
        printf("%s           %5Id   %5Id\n",kayitlar[i].isim,kayitlar[i].kod,kayitlar[i].telNo);
        printf("Yeni isim : ");
        scanf("%s",kayitlar[i].isim);
        printf("Yeni Kod : ");
        scanf("%Id",&kayitlar[i].kod);
        printf("Yeni Numara : ");
        scanf("%Id",&kayitlar[i].telNo);

        Dosya=fopen("TelefonRehber.txt","w");
        fwrite(kayitlar,sizeof(rehber)*sayi,1,Dosya);
        fclose(Dosya);
                 printf("Isleme Devam Etmek Ýstermisiniz <e/h>");
      scanf("%s",&devam);
 if ((devam == 'E') || (devam == 'e'))

            KaydiDuzenle();
            else
            {

                main();
            }


}
void IsimBul()
{
    system("cls");
    char devam='e';
    rehber eleman;
    FILE *fp;
    char ara1[20];
    printf("\nAranacak Ad:");
    scanf("%s",ara1);
    fp=fopen("TelefonRehber.txt","r");
   // fseek(fp, 0, 0);


    while (fread(&eleman, sizeof(rehber), 1, fp)==1)
    {

        if(strcmp(eleman.isim,ara1)==0)
        {

            printf("\nIsim	   : %s" ,eleman.isim);
            printf("\nKod : %Id" ,eleman.kod);
            printf("\nNumara      : %Id",eleman.telNo);

            break;

        }

    }
    fclose(fp);
    printf("İşleme Devam Etmek İstermisiniz <e/h>");
scanf("%s",&devam);
 if ((devam == 'E') || (devam == 'e'))
            IsimBul();
            else

                main();

}
void NoBul()
{
system("cls");

    char devam='e';
    rehber eleman;
    FILE *fp;
    long int ara1;
    printf("\nAranacak No:");
    scanf("%ld",&ara1);
    fp=fopen("TelefonRehber.txt","r");
//fseek(fp, 0, 0);

    while (fread(&eleman, sizeof(rehber), 1, fp)==1)
    {

        if(eleman.telNo==ara1)
        {
            printf("\nIsim	   : %s" ,eleman.isim);
            printf("\nKod : %Id" ,eleman.kod);
            printf("\nNumara      : %Id",eleman.telNo);
        }
    }
    fclose(fp);
    printf("İşleme Devam Etmek İstermisiniz <e/h>");
scanf("%s",&devam);
 if ((devam == 'E') || (devam == 'e'))
            NoBul();
            else
                main();

}
void KayitSil()
{
    system("cls");
    char secim,devam='e';
        int kacinci=-1;
    long int kod;
    int bulundu=0;
    rehber BulunanKayit;
    FILE *fp;
    printf("Kod Giriniz:");
    scanf("%ld",&kod);

    fp=fopen("TelefonRehber.txt","r+");


    while (fread(&BulunanKayit,sizeof(rehber),1,fp) == 1)
    {
        if (BulunanKayit.kod == kod)
        {
            bulundu=1;
            break;
        }
        else
            kacinci+=1;
    }
    if (bulundu == 1)
    {
        fseek(fp,(kacinci+1)*sizeof(rehber),SEEK_SET);
        strcpy(BulunanKayit.isim,"");
        BulunanKayit.kod=NULL;
        BulunanKayit.telNo=NULL;
        fwrite(&BulunanKayit,sizeof(rehber),1,fp);
        fclose(fp);
    }
    else
    {
        fclose(fp);
        printf("Kayit Bulunamadi!\nTekrar silme yapmak ister misiniz?(E/H)");
        scanf("%s",&secim);
        if ((secim == 'E') || (secim == 'e'))
            KayitSil();

    }
        printf("İşleme Devam Etmek İstermisiniz <e/h>");
scanf("%s",&devam);
 if ((devam == 'E') || (devam == 'e'))
            KayitSil();
            else
                main();

}
