#include <string>
#include <stdlib.h>
#include <fstream> 
#include <iomanip>
#include <locale.h>

#include <iostream>
using namespace std;

class Insaat {




public:
	string birim;
	string fiyat;
	string marka;
	string urunNo;
	string urunAd;

	string GirilenUrunNo;

	string girilenurunguncelleme;
	
	

	
	string girilenprojeno;

	string projeAdi;
	string projeSorumlusu;
	string projeNo;
	string ProjeKontrolor;
	string ProjeFirma;

	
	
	string hakedisNo;


	
	
	void insaatFonk() {      //inşaat  Menüsünü açıyor
		int secim;
	
		cout << " - - - - - - - - - - -" << endl;
		cout << "1.Urun islemleri... " << endl;
		cout << "2.Proje Islemleri.... " << endl;
		cout << "3.Hakediş Islemleri... " << endl;
		cout << "0.Çıkış...." << endl;
		cout << "Seciminiz..: ";
		cin >> secim;
		cout << endl;
		system("cls");
		switch (secim)
		{
		case 1:urunIslemi();
			break;
		case 2: projeIslemleri();
			break;
		case 3:HakedisIslem();
			break;
		case 0:Cikis();
			break;
		default:cout << "Hatalı Seçim" << endl;
			break;
		}
	}

	void urunIslemi() {//Ürün işlemleri Menüsünü açıyor
		int secim1;
		cout << "Ürün İşlemleri" << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "1.Ürün Ekle " << endl;
		cout << "2.Ürün Sil" << endl;
		cout << "3.Ürün Listele" << endl;
		cout << "4.Ürün Güncelle" << endl;
		cout << "5.Ürün Ara" << endl;
		cout << "0.Üst Menü" << endl;
		cout << "Seciminiz..: ";
		cin >> secim1;
		system("cls");
		switch (secim1)
		{
		case 1:UrunEkle();
			break;
		case 2:UrunSil();
			break;
		case 3:UrunListele();
			break;
		case 4:UrunGuncelle();
			break;
		case 5:UrunAra();
			break;

		case 0:Ustmenu();
			break;
		default:cout << "Hatalı Seçim" << endl;
			break;
		}
	}

	void UrunEkle() {
		fstream Urunler;//dosyayi oluşturuyor
		Urunler.open("Urunler.txt", ios::out | ios::in | ios::app);//dosyayi açıyor


		cout << "Ürün no Giriniz..:"<<endl;
		cin >> urunNo;
		


		

		bool ukontrol = UrunVarMi(urunNo);//ürün numarasını kontrol ediyor varsa ürün bulunmaktadır yazıyor yoksa ürün dosyaya ekleniyor
		if (ukontrol == true) {
			cout << "Bu ürün Bulunmaktadir.";
		}
		else {
			
			cout << "ürün ad Giriniz..:"<<endl;
			cin >> urunAd;



			cout << "ürün birim Giriniz..:" << endl;
			cin >> birim;

			cout << "ürün fiyat Giriniz..:" << endl;
			cin >> fiyat;

			cout << "ürün marka Giriniz..:" << endl;
			cin >> marka;


			cout << endl;
			Urunler << urunNo << endl << urunAd << endl << birim << endl << fiyat << endl << marka << endl;
			Urunler << endl;
		}
		Urunler.close();//dosyayi kapatıyor
		int menudonme;
		cout << "Tekrar ürün Eklemek Ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:UrunEkle();
			break;
		case 2:urunIslemi();
			break;
		default:cout << "Hatalı Seçim";
			break;
		}
	}

	void UrunSil() {
		string SilinecekUrun;
		cout << "Silinecek ürün Numarası..:"<<endl;
		cin >> SilinecekUrun;
		ifstream dosyaoku("Urunler.txt");//dosyamızı açıyor
		ofstream dosyayaz("Urunler.tmp");//geçici dosya açıyor
		
		
			if (SilinecekUrun == urunNo) {//silinecek ürün numarası, ürün no ya eşitse bilgiler ekrana yazdırılıyor
				cout << "\n Dosyadaki Kayıtlar \n";
				cout << "ürün no..:" << urunNo << endl;
				cout << "ürün ad..:" << urunAd << endl;
				cout << "ürün birim ..:"<<birim<<endl;
				

				cout << "ürün fiyat ..:" << fiyat << endl;
	

				cout << "ürün marka .:" << marka << endl;
			

			}
			else {
				dosyayaz << urunNo << " " << urunAd << endl;//geçici dosyaya yazıyor
			}
		
		dosyayaz.close();//dosya kapatma
		dosyaoku.close();//dosya kapatma
		remove("Urunler.txt");//
		rename("Urunler.tmp", "Urunler.txt");//geçici dosyayı asıl dosyamıza aktarıyor
		int menudonme;
		cout << "Menüye Dönmek İçin Sayı girin.... :  (1-evet)/(2-hayır)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:urunIslemi();
			break;
		case 2:insaatFonk();
			break;
		default:cout << "Hatalı Seçim";
			break;
		}
	}



	void UrunAra(){
	
	
		fstream Urunler;//dosyamız

		Urunler.open("Urunler.txt");//dosyayı açıyor

	

		cout << "Aranacak ürün no giriniz:" << endl;
		cin >> GirilenUrunNo;
		if(GirilenUrunNo==urunNo){
		Urunler >> urunNo >> urunAd >> birim >> fiyat >> marka;
		cout << "ürün Adi..:" << urunAd << endl << "ürün  No..:" << urunNo << endl << "birim" << birim << endl << "marka" << marka << endl << "fiyat" << fiyat << endl;

		}

		Urunler.close();//dosyayı kapatıyorum
		int menudonme;
		cout << "Menüye Dönmek İçin Sayı girin.... :  (1-evet)/(2-hayır)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:urunIslemi();
			break;
		case 2:insaatFonk();
			break;
		default:cout << "Hatalı Seçim";
			break;
		}

	
	}
	void UrunListele() {
		fstream Urunler;//dosyamız
	
		Urunler.open("Urunler.txt");//dosyayı açıyor
	

			Urunler >> urunNo >> urunAd>>birim>>fiyat>>marka;//dosyadan değişkenlerimi alıyorum
		
			cout << "ürün Adi..:" << urunAd << endl << "ürün No..:" << urunNo << endl<<"birim"<<birim<<endl<<"marka"<<marka<<endl<<"fiyat"<<fiyat<< endl;
		
		Urunler.close();//dosyayı kapatıyorum
		int menudonme;
		cout << "Menüye Dönmek İçin Sayı girin.... :  (1-evet)/(2-hayır)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:urunIslemi();
			break;
		case 2:insaatFonk();
			break;
		default:cout << "Hatalı Seçim";
			break;
		}
	}
	void UrunGuncelle() {

		fstream Urunler;//dosyayı oluşturuyor
		Urunler.open("Urunler.txt");
		ifstream dosyaoku("Urunler.txt", ios::in);
		ofstream dosyayaz("Urunler.tmp", ios::out);

		cout << "güncellenecek ürün Numarasını Giriniz..:";
		cin >> girilenurunguncelleme;
		
		while (!dosyaoku.eof()) {
			if (urunNo == girilenurunguncelleme) {

				cout << "yeni ürün no gir";
				cin >> urunNo;
				cout << endl;
				cout << "ürün adı";
				cin >> urunAd;
				cout << endl;
				cout << "ürün birim";
				cin >> birim;
				cout << endl;
				cout << "marka";
				cin >> marka;
				cout << endl;
				cout << "fiyat";
				cin >> fiyat;

				cout << endl;
				Urunler << urunNo << endl << urunAd << endl << marka << endl << fiyat << endl << birim << endl;
				Urunler << endl;
			}
		}
		
		dosyayaz.close();//dosyayı kapatıyorum
		dosyaoku.close();//dosyayı kapatıyorum
		remove("Urunler.txt");//
		rename("Urunler.tmp", "Urunler.txt");


		int menudonme;
		cout << "Tekrar ürün güncellemek için sayı girin.......:  (1-evet)/(2-hayır)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:UrunEkle();
			break;
		case 2:urunIslemi();
			break;
		default:cout << "Hatalı Seçim";
			break;
		}




	}
	void Ustmenu() {
		insaatFonk(); //Üst menü
	}

	void projeIslemleri() {//proje işlemleri
		int secim2;
		cout << "proje İşlemleri" << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "1.proje Ekle " << endl;
		cout << "2.proje Sil" << endl;
		cout << "3.proje Listele" << endl;
		cout << "0.Üst Menü" << endl;
		cout << "Seçiminiz..: ";
		cin >> secim2;
		system("cls");
		switch (secim2)
		{
		case 1:ProjeEkle();
			break;
		case 2:ProjeSil();
			break;
		case 3:ProjeListele();
			break;
		case 0:Ustmenu();
			break;
		default:cout << "Hatalı Seçim" << endl;
			break;
		}
	}

	void ProjeEkle() {
		fstream Projeler;//musteri dosyasi
		Projeler.open("Projeler.txt", ios::out | ios::in | ios::app);//proje dosyasini açıyor
		cout << "proje Numarası Giriniz..:";
		cin >> projeNo;
		cout << "proje Adı Giriniz..: ";
		cin >> projeAdi;
		cout << endl;
		cout << "proje sorumlusu Giriniz..:";
		cin >> projeSorumlusu;
		cout << endl;
		cout << "proje yürütücü firma Giriniz..:";
		cin >> ProjeFirma;
		cout << endl;

		bool mkontrol = projevarmikontrol(projeNo);//eğer aynı proje numarası varsa bu proje numarası vardır dedirtiyorum yoksa dosyaya yazıyorum
		if (mkontrol == true) {
			cout << "Bu proje Numarası Vardır.";
		}
		else {
			Projeler << endl << projeNo<<endl << projeAdi << endl << projeSorumlusu <<endl<< ProjeKontrolor<< endl<<ProjeFirma<<endl;
		}
		Projeler.close();//dosya kapatıyorum
		int menudonme;
		cout << "proje Eklemek Ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:ProjeEkle();
			break;
		case 2:projeIslemleri();
			break;
		default:cout << "Hatalı Seçim";
			break;
		}
	}

	void ProjeSil() {
		string silinendeger;
		cout << "Silinecek projenin Numarası..:";
		cin >> silinendeger;
		ifstream dosyaoku("Projeler.txt");
		ofstream dosyayaz("Projeler.tmp");
		if (hakedisNo =="" && silinendeger == projeNo) {
			//dosyadan değişkenleri alıyorum

		//silinendeğer proje numarasına eşitse dosyadaki kaydı gösterip siliyorum
				cout << "\nDosyadaki Kayit \n";
				cout << "proje No..:" << projeNo << endl;
				cout << "proje Adı..:" << projeAdi << endl;
				cout << "proje Firma..:" << ProjeFirma << endl;
				cout << "proje Sorumlu..:" << projeSorumlusu << endl;
				cout << "Proje Kontrolörü..:" << ProjeKontrolor << endl;
			
			

		}
	
		else {
				cout<<"hakediş nosu var"; 
			}

		
		dosyayaz.close();//dosyayı kapatıyorum
		dosyaoku.close();//dosyayı kapatıyorum
		remove("Projeler.txt");//
		rename("Projeler.tmp", "Projeler.txt");//
		int menudonme1;
		cout << "Menüye Dönmek İçin Sayı girin.... :  (1-evet)/(2-hayır)";
		cin >> menudonme1;
		switch (menudonme1)
		{
		case 1:projeIslemleri();
			break;
		case 2:insaatFonk();
			break;
		default:cout << "Hatali Secim";
			break;
		}
	}

	void ProjeListele() {
		fstream Projeler;//dosya oluşturuldu
		Projeler.open("Projeler.txt");//dosyayı açıyorum

			Projeler >> projeAdi >> projeSorumlusu >> ProjeKontrolor >> projeNo>> hakedisNo>>ProjeFirma;//değişkenlerimi dosyadan alıyorum
			
			cout << "proje No..:" << projeNo << endl << "proje Adı..:" << projeAdi << endl << "projeSorumlusu..:" << projeSorumlusu << endl;
			cout << "proje kontrolörü.... : " << ProjeKontrolor << endl<<"proje firması:" << ProjeFirma << endl << "Hakediş no:" << hakedisNo << endl;//ekrana yazdıyorum
	
		Projeler.close();//dosyayı kapatıyorum
		int menudonme;
		cout << "Menüye Dönmek İçin Sayı girin.... :  (1-evet)/(2-hayır)";
		cin >> menudonme;
		switch (menudonme)
		{
		case 1:projeIslemleri();
			break;
		case 2:insaatFonk();
			break;
		default:cout << "Hatalı Seçim";
			break;
		}


	}

	void HakedisIslem() {// Hakediş İşlemleri Menüsü
		int secim3;
		cout << "hakediş Kayıt İşlemleri" << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "1.projeye hakediş Ekle " << endl;
		cout << "2..projeden hakediş  Sil  (...Proje de var olan hakedişler silinmez uyarı verilir.....)" << endl;
		cout << "3..proje hakediş  Listele" << endl;
		cout << "0.Ust Menu" << endl;
		cout << "Seciminiz..: ";
		cin >> secim3;
		system("cls");
		switch (secim3)
		{
		case 1:HakedisEkle();
			break;
		case 2:HakedisSil();
			break;
		case 3:HakedisListele();
			break;
		case 0:Ustmenu();
			break;
		default:cout << "Hatalı Seçim" << endl;
			break;
		}

	}

	void HakedisEkle() {
		fstream hakedis;//dosya oluşturuldu
		hakedis.open("Hakedis.txt", ios::in | ios::out | ios::app);//dosyamı açıyorum
		
		
		cout << " hakediş için  proje no giriniz.......:"<<endl;
		cin >> girilenprojeno;
		cout << "hakediş Giriniz..:"<<endl;
		cin >> hakedisNo;
		if (girilenprojeno ==projeNo ) {



			hakedis << hakedisNo << endl << projeNo<< endl<<projeAdi<<endl<<ProjeFirma<<endl<<ProjeKontrolor<<endl<<projeSorumlusu<<endl;//dosyaya yazıyorum

		}
		else
		{
			cout << "Bu proje Numarası Yoktur..... "<<endl;
		}
		hakedis.close();//dosyayı kapatıyorum
		int menudonme3;
		cout << "Tekrar hakediş Eklemek ister Misiniz?  (1-e)/(2-h)";
		cin >> menudonme3;
		switch (menudonme3)
		{
		case 1:HakedisEkle();
			break;
		case 2:HakedisIslem();
			break;
		default:cout << "Hatalı Seçim";
			break;
		}
	}

	void HakedisSil() {
		string hakedisSec;//değişkenim
		cout << "Silinecek hakediş Numarası..:"<<endl;
		cin >> hakedisSec;//musteri numarasini alıyorum
		ifstream dosyaoku("Hakedis.txt");//dosyayı okuyorum
		ofstream dosyayaz("Hakedis.tmp");//geçici dosyam
		while (!dosyaoku.eof() && dosyaoku >> urunNo >> hakedisNo) {//dosyamdan değişkenimi alıyorum
			if (hakedisSec == hakedisNo && hakedisNo!="" ) {//değişkenlerim eşitse dosyadaki kayiti gösterip siliyor
				cout << "\n Dosyadaki Kayıtlar \n";
				cout << "hakediş Numarası..:" << urunNo << endl;
				cout << "proje Numarası..:" << hakedisNo << endl;
			
			}
			
		
		
			else {
				cout << "Projenin hakediş nosu var silinemez" << endl;
			}
		int menudonme5;
		cout << "Menüye Dönmek İçin Sayı girin.... :  (1-evet)/(2-hayır)";
		cin >> menudonme5;
		switch (menudonme5)
		{
		case 1:HakedisIslem();
			break;
		case 2:insaatFonk();
			break;
		default:cout << "Hatali Secim";
			break;
		}
		}
	}

	void HakedisListele() {
		fstream hakedis;//dosya oluşturuldu
		hakedis.open("Hakedis.txt");//dosyamı açıyorum
		
			hakedis >> hakedisNo >> projeNo;//değişkenlerimi alıyorum
			
			cout << "Hakediş no..:" << hakedisNo << endl << "proje No..:" << projeNo << endl << "proje adı....:" << projeAdi << endl;
			cout << "firma.....:" << ProjeFirma << endl << "proje kontrolörü......:" << ProjeKontrolor << endl << "proje sorumlusu....:" << projeSorumlusu << endl;//değişkenlerimi ekrana yazdıyorum
		
		hakedis.close();//dosyayi kapatıyorum
		int menudonme6;
		cout << "Menüye Dönmek İçin Sayı girin.... :  (1-evet)/(2-hayır)";
		cin >> menudonme6;
		switch (menudonme6)
		{
		case 1:HakedisIslem();
			break;
		case 2:insaatFonk();
			break;
		default:cout << "Hatalı Seçim";
			break;
		}
	}

	void Cikis() {//Çıkış fonksiyonu
		exit(0);
	}

	
	
	bool HakedisKontrol(string hakedisno) {
		fstream hakedisDosya("Hakedis.txt");//dosya oluşturuldu
		while (!hakedisDosya.eof() && hakedisDosya >> hakedisNo) {//değişkenlerimi alıyorum
			if (hakedisno ==hakedisNo)//değişkenlerim eşitse true değilse false döndürüyor
			{
				return true;
			}
		}
		return false;
		hakedisDosya.close();//dosyayı kapatıyor
	}

	bool UrunVarMi(string urunNoKontrol) {
		fstream Urunler("Urunler.txt");//dosya oluşturuldu
		while (!Urunler.eof() && Urunler >>urunNo) {//dosyadan değişkenlerimi alıyorum
			if (urunNo == urunNoKontrol) {//değişkenler eşitse true değilse false dönüyor
				return true;
			}
		}
		return false;
		Urunler.close();//dosyayi kapatıyorum
	}

	bool projevarmikontrol(string projeKontrol) {
		fstream Projeler("Projeler.txt");//dosya oluşturuldu	
		while (!Projeler.eof() && Projeler >> projeAdi >> projeSorumlusu >> ProjeKontrolor >> projeNo) {//dosyadan değişkenleri alıyorum
			if (projeKontrol == projeNo) {//değişkenler eşitse true değilse false dönüyor
				return true;
			}
		}
		return false;
		Projeler.close();//dosyayi kapatıyorum
	}

};

int main()
{
	setlocale(LC_ALL, "turkish");
	Insaat insaat;
	insaat.insaatFonk();
	system("pause");
	return 0;
}