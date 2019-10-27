#include <iostream>
using namespace std;
//Ali Burhan Keskin
//100 karaktere kadar girilebilir

int main(int argc, char** argv) {
	
	 
    setlocale(LC_ALL, "Turkish"); //Türkçe karakter yardımı
	char girilenMetin[100];//Metnin karakterlerinin Dizisi
	int a,b,k = 0,j = 0;//Formüllerde ve dönülerde kullanıcalak değişkenler
	int secim=0;//Hangi şifreleme hethodu kullanılacak
	int harf_sayisi = 0 ;//Harf Sayısı
	
	//Alfabe
	char alp[30] = {' ','a','b','c','ç','d','e','f','g','ğ','h','ı','i','j','k','l','m','n','o','ö','p','r','s','ş','t','u','ü','v','y','z'};
 	
	cout <<"Metni Griniz (büyük harf girmeyiniz): ";//Kullanıcadan metin alma
	while((girilenMetin[harf_sayisi] = getchar())!='\n')//kullanıcını girdiği metni karakterlerine ayırıyoruz.
        harf_sayisi++ ;
      //i metindeki karakter sayısı
	  
    char EcrStr[harf_sayisi],DcrStr[harf_sayisi],ch;//EcrStr => Şifrelenmiş Metin Dizisi , DcrStr => Şifresi Çözüşmüş Metin Dizisi
	    
	cout <<"Sezar,Rot13 ve Kaydırma Methodlarını kullanmak için '1' giriniz  \n";
	cout <<"Doğrusal Methodunu kullanmak için '2' giriniz  \n";
	cout <<"Yerine koyma Methodunu kullanmak için '3' giriniz  \n";
	cout <<"Lütfen bir seçin yapınız :   ";
	cin >> secim;  
	    
	    
 //Kullanıcıdan şifrelencek method için seçim alma      
	switch (secim)
      {
//////////////////////////////////////
//Sezar,Rot13 ve Kaydırma Şifreleme///
/////////////////////////////////////
      case 1:{
      	
			//Sezar şifrelemsindeki gerekli olan anahatar
 			int key=0;
		    cout << "Anahtari Girin: ";
		    cin >> key;
		
		//gerekli olan döngü
		for(k = 0 ; k < harf_sayisi ; k ++){
				for(j = 0 ; j < 30 ; j++){
					if(girilenMetin[k] == alp[j]){
						
						if(j + key > 29 ){
							EcrStr[k] = alp[(j+key)%29];
							 cout << "\nyeni : "<<EcrStr[k];
						}
						else
						{
							EcrStr[k] = alp[j+key];
							cout << "\nyeni : "<<EcrStr[k];
						}	
					}
				}
			}
			
			cout << "\nGirilen Metin = >  "<<girilenMetin;
			cout << "\nŞifrelenmiş  Metin = >  "<<EcrStr;
			
			for(k = 0 ; k < harf_sayisi ; k ++){
				
				for(j = 0 ; j < 30 ; j++){
					
					if(EcrStr[k] == alp[j]){
						
						if((j - key) < 0){
						DcrStr[k] = alp[(j - key) + 28];
						}
						else{
					     DcrStr[k] = alp[(j-key)];
						}
					}
				}
				
			}
			cout << "\nÇözülen Şifrelenmiş Metin = >  "<<DcrStr;	        
	break;
	  }
            
//////////////////////////////////////
//Doğrusal Şifreleme///
/////////////////////////////////////
	   case 2:{
	            	
		cout << "Doğrusal Şifreleme (ax+b)\n";
	    cout << "a değerini girin(çarpan): ";
	    cin >> a;
	    cout << "b değerini girin(toplama): ";
	    cin >> b;
	    
		//Şifreleme işlemi için gerekli döngü
		
		for(k = 0 ; k < harf_sayisi ; k ++){
			for(j = 0 ; j < 30 ; j++){
				if(girilenMetin[k] == alp[j]){
					EcrStr[k] = alp[((a*j)+b)%30];
				}
			}
		}
		
		cout << "\nGirilen Metin = >  "<<girilenMetin;
		cout << "Şifrelenmiş  Metin = >  "<<EcrStr;
		
	   //Şifreli metni çözmek için gerekli döngü
	   
		for(k = 0 ; k < harf_sayisi ; k ++){
			
			for(j = 0 ; j < 30 ; j++){
				
				if(EcrStr[k] == alp[j]){
					
					if((j-b)<0){
					DcrStr[k] = alp[((j-b+30)/a)%30];
					}
					else{
					DcrStr[k] = alp[((j-b)/a)%30];
					}
				    
				}
			}
			
		}
		cout << "\nÇözülen Şifrelenmiş Metin = >  "<<DcrStr<<"\n";
      	
			break;
		 }
//////////////////////////////////////
//Yerine koyma methodu Şifreleme///
/////////////////////////////////////
	   case 3:{
	   	
	   	char alp_rand[30];
	   	
	   	for(k=0;k<30;k++){//Yerine koyma methodu için tersine bir alfabe oluşturuluyor
	   		
	   		alp_rand[k] = alp[29-k];
		   }
	   	
	   	for(k = 0 ; k < harf_sayisi ; k ++){
			for(j = 0 ; j < 30 ; j++){
				if(girilenMetin[k] == alp[j]){
					
					    //cout << "\neski : "<<girilenMetin[k];
						EcrStr[k] = alp_rand[j];
						//cout << "\nyeni : "<<EcrStr[k];
				}
			}
		}
	   	
	   	for(k = 0 ; k < harf_sayisi ; k ++){
			for(j = 0 ; j < 30 ; j++){
				if(EcrStr[k] == alp_rand[j]){//Random alfabadeki yeri bulunuyor
					
						DcrStr[k] = alp[j];
						//cout << "\nÇözülmüş harf : "<<DcrStr[k];
				}
			}
		}
	   	
		break;
	   }
	  default:{
	  		cout << "\nYanlış seçim  ";
		break;
	  }
	  	
	    
 }   
	   
	   
	    
  
	
	return 0;
}