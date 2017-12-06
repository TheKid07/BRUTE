#include<iostream.h>
#include<conio.h>
#include<fstream.h>

/* character-set based brute-forcing algorithm written by aravinth7820@gmail.com*/

char password[10];
char passwordcharset[10];
char passwordkc[10];
int min=0, max,x=0,y,temp;
int trueval_setchar=0, trueval_setchar2=0, trueval_knownc=0;

void init()                 //Sets default falues to the arrays
{ for (int i=0; i<10;++i)
  { ::passwordkc[i]=11;
    ::passwordcharset[i]=11;
  }
}

void initiate()
{ for (int i=0; i<::x; ++i) //Sets default value of the main array(password[10] to zeroes
    ::password[i]=48;
}

int confirmation()    //Terms and conditions
{ void asthetics();
  asthetics();
  cout<<endl<<endl<<endl;
  cout<<"This program is provided as is, as is a royalty free open-source application."<<endl;
  cout<<"Feel free to modify, use, change, market, do whatever you want with it as long";
  cout<<"\nas you give the appropriate credit to the authors where credit is due"<<endl<<endl;
  cout<<"Brute is designed purely for good and NOT EVIL. If you are planning on using the";
  cout<<"tool for malicious purposes that are not authorized by the company/person you";
  cout<<"\nare performing assessments for, you are violating the terms of service and license of this tool."<<endl<<endl;
  cout<<"By hitting yes, you agree to terms of service and that you will only use this";
  cout<<"\ntool for lawful purposes only. Do you agree to the terms of service[y/n]?"<<endl;
  char confirmation;
  cout<<">>";
  cin>>confirmation;
  if(confirmation=='n'||confirmation=='N')
    return 0;
  if(confirmation=='Y'||confirmation=='y')
    return 1;
  return 0;
}

void knownc()       //records the user-inupt known characters into passwordkc[10]
{ int resp3, x;
  char respkn, tempkc;
  cout<<endl<<"Do yo know any characters of the password[y/n]?"<<endl<<">>";
  cin>>respkn;
  if(respkn=='y'||respkn=='Y')
  { ::trueval_knownc=1;
    cout<<endl<<"How many characters do you knnow?"<<endl<<">>";
    cin>>resp3;
    for (int i=0;i<resp3;++i)
    { cout<<"Enter the known character-position of the "<<::max<<"-character string:"<<endl<<">>";
      cin>>x;
      cout<<endl<<"Enter the value for "<<x<<"th character"<<endl<<">>";
      cin>>tempkc;
      if(tempkc==' ')
       ::passwordkc[x-1]=12; //Solves conflict caused due blankspace
      else
       ::passwordkc[x-1]=tempkc;
    }
  }
  if(respkn=='n'||respkn=='N')
    ::temp=1;
}

int setcharset()    //sets char-list to characters of the array
{ int respscs;
  cout<<"To how positions of the array do you want to set character sets?"<<endl;
  cout<<"The max size array's settings will be neglected in the minimum size array. So character sets for max size array only recieved."<<endl;
  cout<<">>";
  cin>>respscs;
  cout<<"\t1. Lower case alphabet"<<endl;
  cout<<"\t2. Upper case alphabet"<<endl;
  cout<<"\t3. Numbers "<<endl;
  cout<<"\t4. Symblos"<<endl;
  cout<<"\t5. Blankspace"<<endl;
  cout<<"\t6. Alphabet(lower+upper)"<<endl;
  for (int i=1;i<=respscs;++i)
  {  cout<<"For which position do you wish to specify the character-set?"<<endl<<">>";
     int h,k;
     cin>>h;
     cout<<"Enter the character set for "<<h<<"position:"<<endl<<">>";
     k=h-1;
     cin>>::passwordcharset[k];

  }
  return 1;
}


int menu() //Presents with the menu
{ void asthetics();
  asthetics();
  int respmm, respmm2, tempmm;
  void Brute();
  cout<<"Choose one of the following opitons to continue:(1-3)"<<endl;
  cout<<"1. Traditional bruteforce wordlist"<<endl;   //No conditions.Tries out every possible combination of numbers,symbols and the alphabet
  cout<<"2. Hybrid bruteforce wordlist (has sub-menu)"<<endl;
  cout<<endl<<">>";
  cin>>respmm;
  tempmm=0;
  option:
  switch (respmm)
  { case 1:
    knownc();
    Brute();
    return 1;
    case 2 :
    cout<<"\n Select one of the following options to continue:"<<endl<<endl;
    cout<<"1. Set character set to the characters of the password string"<<endl;
    if (::min==::max)
    { cout<<"2. Set known values to character positions"<<endl;
      cout<<"\n[NOTE: You'll be prompted with the same options again so as set parameters to the other potion.]"<<endl<<">>";
      tempmm++;
    }
    else
      cout<<">>";
    cin>>respmm2;
    asthetics();
    if(respmm2==1)
    { ::trueval_setchar=setcharset();
      if(tempmm==1)
	if(::min==::max)
	{ cout<<"Do you want to go back to menu to set known characters?[y/n]"<<endl<<">>";
	  char a;
	  cin>>a;
	  if(a=='y'||a=='Y')
	    goto option;
	  if(a=='n'||a=='N')
	    cout<<"Brute will now show you the fifty states[Press Enter]"<<endl;
	}
    }
    if (respmm2==2)
    { knownc ();
      if (tempmm==1)
	goto option;
    }
    else
      getch ();
    term:
    return 2;
  }
  return 0;
}


void req()  //Gets the string length
{ void asthetics();
  asthetics();
  cout<<endl<<"Enter the minimum number of characters required for the desired password string"<<endl<<">>";
  cin>>::min;
  cout<<endl<<"Enter the maximum number of characters required for the desired password string"<<endl<<">>";
  cin>>::max;
  if(::min>::max)
  { cout<<"Minimum can't be greater than maximum. Try again"<<endl;
    clrscr ();
    req();
  }

}
int set_lwr_inc(int a)
{ if(::passwordcharset[a]=='1')
    return 97;
  if(::passwordcharset[a]=='2')
    return 65;
  if(::passwordcharset[a]=='3')
    return 48;
  if(::passwordcharset[a]=='4')
  { ::trueval_setchar=1;
    ::trueval_setchar2=1;
    return 33;
  }
  if(::passwordcharset[a]=='5')
    return 32;
  if(::passwordcharset[a]=='6')
  { ::trueval_setchar=1;
    return 65;
  }
  if(::passwordcharset[a]==11)
    return 32;


}

int set_upr_inc(int a)
{ if(::passwordcharset[a]=='1')
    return 122;

  if(::passwordcharset[a]=='2')
    return 90;
  if(::passwordcharset[a]=='3')
    return 57;
  if(::passwordcharset[a]=='4')
    return 47;
  if(::passwordcharset[a]=='5')
    return 32;
  if(::passwordcharset[a]=='6')
    return 90;
  if(::passwordcharset[a]==11)
    return 126;
}


int set_sec_lwr_inc(int a)
{ if(::passwordcharset[a]=='4')
    return 58;
  if(::passwordcharset[a]=='6')
    return 97;

}

int set_sec_upr_inc(int a)
{ if(::passwordcharset[a]=='4')
    return 63;
  if(::passwordcharset[a]=='6')
    return 122;
}

int tert_set_lwr_inc(int a)
{ if(::passwordcharset[a]=='4')
    return 91;
}

int tert_set_upr_inc(int a)
{ if(::passwordcharset[a]=='4')
    return 96;
}
int quad_set_lwr_inc(int a)
{ if(::passwordcharset[a]=='4')
    return 123;
  return 0;
}
int quad_set_upr_inc(int a)
{ if(::passwordcharset[a]=='4')
    return 126;
  return 0;
}
void charassign(int a, int x)
{ ::password[x]=a;
  if(::trueval_knownc==1)
  { if(::passwordkc[x]==12)
     ::password[x]=32;
    else
     ::password[x]=::passwordkc[x];
  }
  cout<<::password<<endl;

}


void Brute () //Main function for wordlist generation
{
  ofstream myfile;
  int x=::min;
  myfile.open("Brute_wordlist.txt");
  for (int i=x;i<=::max;++i)
  { if(i==10)
     { initiate();
       int a,az,azz,azzz,aza,azaa,azaz,azza;
       a=set_lwr_inc(0);
       az=set_upr_inc(0);
       azz=az; 	azzz=az;
       aza=az;  azaa=az;
       azaz=az; azza=az;
       if(::trueval_setchar==1)
       { azz=set_sec_lwr_inc(0);
	 azzz=set_sec_upr_inc(0);
	 if(::trueval_setchar2==1)
	 { aza=tert_set_lwr_inc(0);
	   azaa=tert_set_upr_inc(0);
	   azaz=quad_set_lwr_inc(0);
	   azza=quad_set_upr_inc(0);
	 }
       }
       for(a,azz,azaz,aza;a<=az||azz<=azzz||aza<=azaa||azaz<=azza;++a,++aza,++azaz,++azz)
       { charassign(a,0);
	 myfile<<::password<<endl;
	 if(trueval_setchar==1)
	 { charassign(azz,0);
	   myfile<<::password<<endl;
	   if(trueval_setchar2==1)
	   {  charassign(aza,0);
	      myfile<<::password<<endl;
	      charassign(azaz,0);
	      myfile<<::password<<endl;
	   }
	 }
	 int c,cz,czz,czzz,czc,czcc,czcz,czzc;
	 c=set_lwr_inc(1);
	 cz=set_upr_inc(1);
	 czz=cz;   czzz=cz;
	 czc=cz;   czcc=cz;
	 czcz=cz;  czzc=cz;
	 if(trueval_setchar==1)
	 { czz=set_sec_lwr_inc(1);
	   czzz=set_sec_upr_inc(1);
	   if(trueval_setchar2==1)
	   { czc=tert_set_lwr_inc(1);
	     czcc=tert_set_upr_inc(1);
	     czcz=quad_set_lwr_inc(1);
	     czzc=quad_set_upr_inc(1);
	   }
	 }
	 for(c,czz,czc,czcz;c<=cz||czz<=czzz||czc<=czcc||czcz<=czzc;++c,++czz,++czc,++czcz)
	 { charassign(c,1);
	   myfile<<::password<<endl;
	   if(trueval_setchar==1)
	   { charassign(czz,1);
	     myfile<<::password<<endl;
	     if(trueval_setchar2==1)
	     {  charassign(czc,1);
		myfile<<::password<<endl;
		charassign(czcz,1);
		myfile<<::password<<endl;
	     }
	   }
	   int v,vz,vzz,vzzz,vzv,vzvv,vzvz,vzzv;
	   v=set_lwr_inc(2);
	   vz=set_upr_inc(2);
	   vzz=vz;    vzzz=vzz;
	   vzv=vz;    vzvv=vz;
	   vzvz=vz;   vzzv=vz;
	   if(trueval_setchar==1)
	   { vzz=set_sec_lwr_inc(2);
	     vzzz=set_sec_upr_inc(2);
	     if(trueval_setchar2==1)
	     { vzv=tert_set_lwr_inc(2);
	       vzvv=tert_set_upr_inc(2);
	       vzvz=quad_set_lwr_inc(2);
	       vzzv=quad_set_upr_inc(2);
	     }
	   }
	   for(v,vzz,vzv,vzvz;v<=vz||vzz<=vzzz||vzv<=vzvv||vzvz<=vzzv;++v,++vzz,++vzv,++vzvz)
	   { charassign(v,2);
	     myfile<<::password<<endl;
	     if(trueval_setchar==1)
	     { charassign(vzz,2);
	       myfile<<::password<<endl;
	       if(trueval_setchar2==1)
	       { charassign(vzv,2);
		 myfile<<::password<<endl;
		 charassign(vzvz,2);
		 myfile<<::password<<endl;
	       }
	     }
	     int b,bz,bzz,bzzz,bzb,bzbb,bzbz,bzzb;
	     b=set_lwr_inc(3);
	     bz=set_upr_inc(3);
	     bzz=bz;	bzb=bz;
	     bzzz=bz;  bzbb=bz;
	     bzbz=bz;   bzzb=bz;
	     if(trueval_setchar==1)
	     { bzz=set_sec_lwr_inc(3);
	       bzzz=set_sec_upr_inc(3);
	       if(trueval_setchar2==1)
	       { bzb=tert_set_lwr_inc(3);
		 bzbb=tert_set_upr_inc(3);
		 bzbz=quad_set_lwr_inc(3);
		 bzzb=quad_set_upr_inc(3);
	       }
	     }
	     for(b,bzz,bzb,bzbz;b<=bz||bzb<=bzbb||bzz<=bzzz||bzbz<=bzzb;++b,++bzb,++bzz,++bzbz)
	     { charassign(b,3);
	       myfile<<::password<<endl;
	       if(trueval_setchar==1)
	       { charassign(bzz,3);
		 myfile<<::password<<endl;
		 if(trueval_setchar2==1)
		 { charassign(bzb,3);
		   myfile<<::password<<endl;
		   charassign(bzbz,3);
		   myfile<<::password<<endl;
		 }
	       }
	       int n,nz,nzz,nzzz,nzn,nznn,nzzn,nznz;
	       n=set_lwr_inc(4);
	       nz=set_upr_inc(4);
	       nzz=nz;	  nzn=nz;
	       nzzz=nz;  nznn=nz;
	       nznz=nz;   nzzn=nz;
	       if(trueval_setchar==1)
	       { nzz=set_sec_lwr_inc(4);
		 nzzz=set_sec_upr_inc(4);
		 if(trueval_setchar2==1)
		 { nzn=tert_set_lwr_inc(4);
		   nznn=tert_set_upr_inc(4);
		   nznz=quad_set_lwr_inc(4);
		   nzzn=quad_set_upr_inc(4);
		 }
	       }
	       for (n,nzz,nzn,nznz;n<=nz||nzz<=nzzz||nzn<=nznn||nznz<=nzzn;++nzn,++nznz,++nzz,++n)
	       { charassign(n,4);
		 myfile<<::password<<endl;
		 if(trueval_setchar==1)
		 { charassign(nzz,4);
		   myfile<<::password<<endl;
		   if(trueval_setchar2==1)
		   { charassign(nzn,4);
		     myfile<<::password<<endl;
		     charassign(nznz,4);
		     myfile<<::password<<endl;
		   }
		 }
		 int m,mz,mzz,mzzz,mzm,mzmm,mzmz,mzzm;
		 m=set_lwr_inc(5);
		 mz=set_upr_inc(5);
		 mzz=mz;    mzm=mz;
		 mzzz=mz;   mzmm=mz;
		 mzmz=mz;   mzzm=mz;
		 if(trueval_setchar==1)
		 { mzz=set_sec_lwr_inc(5);
		   mzzz=set_sec_upr_inc(5);
		   if(trueval_setchar2==1)
		   { mzm=tert_set_lwr_inc(5);
		     mzmm=tert_set_upr_inc(5);
		     mzmz=quad_set_lwr_inc(5);
		     mzzm=quad_set_upr_inc(5);
		   }
		 }
		 for(m,mzz,mzm,mzmz;m<=mz||mzz<=mzzz||mzm<=mzmm,mzmz<=mzzm;++m,++mzz,++mzm,++mzmz)
		 { charassign(m,5);
		   myfile<<::password<<endl;
		   if(trueval_setchar==1)
		   { charassign(mzz,5);
		     myfile<<::password<<endl;
		     if(trueval_setchar2==1)
		     { charassign(mzm,5);
		       myfile<<::password<<endl;
		       charassign(mzmz,5);
		       myfile<<::password<<endl;
		     }
		   }
		   int j,jz,jzz,jzzz,jzj,jzjj,jzjz,jzzj;
		   j=set_lwr_inc(6);
		   jz=set_upr_inc(6);
		   jzz=jz;       jzj=jz;
		   jzzz=jz;     jzjj=jz;
		   jzjz=jz;     jzzj=jz;
		   if(trueval_setchar==1)
		   { jzz=set_sec_lwr_inc(6);
		     jzzz=set_sec_upr_inc(6);
		     if(trueval_setchar2==1)
		     { jzj=tert_set_lwr_inc(6);
		       jzjj=tert_set_upr_inc(6);
		       jzjz=quad_set_lwr_inc(6);
		       jzzj=quad_set_upr_inc(6);
		     }
		   }
		   for(j,jzz,jzj,jzjz;j<=jz||jzz<=jzzz||jzj<=jzjj||jzjz<=jzzj;++j,++jzz,++jzj,++jzjz)
		   { charassign(j,6);
		     myfile<<::password<<endl;
		     if(trueval_setchar==1)
		     { charassign(jzz,6);
		       myfile<<::password<<endl;
		       if(trueval_setchar2==1)
		       { charassign(jzj,6);
			 myfile<<::password<<endl;
			 charassign(jzjz,6);
			 myfile<<::password<<endl;
		       }
		     }
		     int aa,aaz,aazz,aazzz,qz,qzz,qzq,qzqz;
		     aa=set_lwr_inc(7);
		     aaz=set_upr_inc(7);
		     azz=aaz;     qz=aaz;
		     aazzz=aaz;   qzz=aaz;
		     qzq=aaz;     qzqz=aaz;
		     if(trueval_setchar==1)
		     { aazz=set_sec_lwr_inc(7);
		       aazzz=set_sec_upr_inc(7);
		       if(trueval_setchar2==1)
		       { qz=tert_set_lwr_inc(7);
			 qzz=tert_set_upr_inc(7);
			 qzq=quad_set_lwr_inc(7);
			 qzqz=quad_set_upr_inc(7);
		       }
		     }
		     for(aa,aazz,qz,qzq;aa<=aaz||aazz<=aazzz||qz<=qzz||qzq<=qzqz;++aa,++aazz,++qz,++qzq)
		     { charassign(aa,7);
		       myfile<<::password<<endl;
		       if(trueval_setchar==1)
		       { charassign(aazz,7);
			 myfile<<::password<<endl;
			 if(trueval_setchar2==1)
			 { charassign(qz,7);
			   myfile<<::password<<endl;
			   charassign(qzq,7);
			   myfile<<::password<<endl;
			 }
		       }
		       int bb,bbz,bbzz,bbzzz,wz,wzz,wzw,wzzw;
		       bb=set_lwr_inc(8);
		       bbz=set_upr_inc(8);
		       bbzz=bbz;     wz=bbz;
		       bbzzz=bbz;    wzz=bbz;
		       wzw=bbz;      wzzw=bbz;
		       if(trueval_setchar==1)
		       { bbzz=set_sec_lwr_inc(8);
			 bbzzz=set_sec_upr_inc(8);
			 if(trueval_setchar2==1)
			  { wz=tert_set_lwr_inc(8);
			    wzz=tert_set_upr_inc(8);
			    wzw=quad_set_lwr_inc(8);
			    wzzw=quad_set_upr_inc(8);
			  }
		       }
		       for(bb,bbzz,wz,wzw;bb<=bbz||bbzz<=bbzzz||wz<=wzz||wzw<=wzzw;++bb,++bbzz,++wz,++wzw)
		       { charassign(bb,8);
			 myfile<<::password<<endl;
			 if(trueval_setchar==1)
			 { charassign(bbzz,8);
			   myfile<<::password<<endl;
			   if(trueval_setchar2==1)
			   { charassign(wz,8);
			     myfile<<::password<<endl;
			     charassign(wzw,8);
			     myfile<<::password<<endl;
			   }
			 }
			 int cc,ccz,cczz,cczzz,rz,rzz,rzr,rzzr;
			 cc=set_lwr_inc(9);
			 ccz=set_upr_inc(9);
			 cczz=ccz;    rz=ccz;
			 cczzz=ccz;   rzz=ccz;
			 rzr=ccz;     rzzr=ccz;
			 if(::trueval_setchar==1)
			 { cczz=set_sec_lwr_inc(9);
			   cczzz=set_sec_upr_inc(9);
			   if(::trueval_setchar2==1)
			   { rz=tert_set_lwr_inc(9);
			     rzz=tert_set_upr_inc(9);
			     rzr=quad_set_lwr_inc(9);
			     rzzr=quad_set_upr_inc(9);
			   }
			 }
			 for (cc,cczz,rz,rzr;cc<=ccz||cczz<=cczzz||rz<=rzz||rzr<=rzzr;++cc,++cczz,++rz,++rzr)
			 { charassign(cc,9);
			   myfile<<::password<<endl;
			   if(::trueval_setchar==1)
			   { charassign(ccz,9);
			     myfile<<::password<<endl;
			     if(::trueval_setchar2==1)
			     { charassign(rz,9);
			       myfile<<::password<<endl;
			       charassign(rzr,9);
			       myfile<<::password<<endl;
			     }
			   }
			 }
		       }
		     }
		   }
		 }
	       }
	     }
	   }
	 }
       }
     }
     if(i==9)
     { initiate();
       int a,az,azz,azzz,aza,azaa,azaz,azza;
       a=set_lwr_inc(0);
       az=set_upr_inc(0);
       azz=az; 	azzz=az;
       aza=az;  azaa=az;
       azaz=az; azza=az;
       if(::trueval_setchar==1)
       { azz=set_sec_lwr_inc(0);
	 azzz=set_sec_upr_inc(0);
	 if(::trueval_setchar2==1)
	 { aza=tert_set_lwr_inc(0);
	   azaa=tert_set_upr_inc(0);
	   azaz=quad_set_lwr_inc(0);
	   azza=quad_set_upr_inc(0);
	 }
       }
       for(a,azz,azaz,aza;a<=az||azz<=azzz||aza<=azaa||azaz<=azza;++a,++aza,++azaz,++azz)
       { charassign(a,0);
	 myfile<<::password<<endl;
	 if(trueval_setchar==1)
	 { charassign(azz,0);
	   myfile<<::password<<endl;
	   if(trueval_setchar2==1)
	   {  charassign(aza,0);
	      myfile<<::password<<endl;
	      charassign(azaz,0);
	      myfile<<::password<<endl;
	   }
	 }
	 int c,cz,czz,czzz,czc,czcc,czcz,czzc;
	 c=set_lwr_inc(1);
	 cz=set_upr_inc(1);
	 czz=cz;   czzz=cz;
	 czc=cz;   czcc=cz;
	 czcz=cz;  czzc=cz;
	 if(trueval_setchar==1)
	 { czz=set_sec_lwr_inc(1);
	   czzz=set_sec_upr_inc(1);
	   if(trueval_setchar2==1)
	   { czc=tert_set_lwr_inc(1);
	     czcc=tert_set_upr_inc(1);
	     czcz=quad_set_lwr_inc(1);
	     czzc=quad_set_upr_inc(1);
	   }
	 }
	 for(c,czz,czc,czcz;c<=cz||czz<=czzz||czc<=czcc||czcz<=czzc;++c,++czz,++czc,++czcz)
	 { charassign(c,1);
	   myfile<<::password<<endl;
	   if(trueval_setchar==1)
	   { charassign(czz,1);
	     myfile<<::password<<endl;
	     if(trueval_setchar2==1)
	     {  charassign(czc,1);
		myfile<<::password<<endl;
		charassign(czcz,1);
		myfile<<::password<<endl;
	     }
	   }
	   int v,vz,vzz,vzzz,vzv,vzvv,vzvz,vzzv;
	   v=set_lwr_inc(2);
	   vz=set_upr_inc(2);
	   vzz=vz;    vzzz=vzz;
	   vzv=vz;    vzvv=vz;
	   vzvz=vz;   vzzv=vz;
	   if(trueval_setchar==1)
	   { vzz=set_sec_lwr_inc(2);
	     vzzz=set_sec_upr_inc(2);
	     if(trueval_setchar2==1)
	     { vzv=tert_set_lwr_inc(2);
	       vzvv=tert_set_upr_inc(2);
	       vzvz=quad_set_lwr_inc(2);
	       vzzv=quad_set_upr_inc(2);
	     }
	   }
	   for(v,vzz,vzv,vzvz;v<=vz||vzz<=vzzz||vzv<=vzvv||vzvz<=vzzv;++v,++vzz,++vzv,++vzvz)
	   { charassign(v,2);
	     myfile<<::password<<endl;
	     if(trueval_setchar==1)
	     { charassign(vzz,2);
	       myfile<<::password<<endl;
	       if(trueval_setchar2==1)
	       { charassign(vzv,2);
		 myfile<<::password<<endl;
		 charassign(vzvz,2);
		 myfile<<::password<<endl;
	       }
	     }
	     int b,bz,bzz,bzzz,bzb,bzbb,bzbz,bzzb;
	     b=set_lwr_inc(3);
	     bz=set_upr_inc(3);
	     bzz=bz;	bzb=bz;
	     bzzz=bz;  bzbb=bz;
	     bzbz=bz;   bzzb=bz;
	     if(trueval_setchar==1)
	     { bzz=set_sec_lwr_inc(3);
	       bzzz=set_sec_upr_inc(3);
	       if(trueval_setchar2==1)
	       { bzb=tert_set_lwr_inc(3);
		 bzbb=tert_set_upr_inc(3);
		 bzbz=quad_set_lwr_inc(3);
		 bzzb=quad_set_upr_inc(3);
	       }
	     }
	     for(b,bzz,bzb,bzbz;b<=bz||bzb<=bzbb||bzz<=bzzz||bzbz<=bzzb;++b,++bzb,++bzz,++bzbz)
	     { charassign(b,3);
	       myfile<<::password<<endl;
	       if(trueval_setchar==1)
	       { charassign(bzz,3);
		 myfile<<::password<<endl;
		 if(trueval_setchar2==1)
		 { charassign(bzb,3);
		   myfile<<::password<<endl;
		   charassign(bzbz,3);
		   myfile<<::password<<endl;
		 }
	       }
	       int n,nz,nzz,nzzz,nzn,nznn,nzzn,nznz;
	       n=set_lwr_inc(4);
	       nz=set_upr_inc(4);
	       nzz=nz;	  nzn=nz;
	       nzzz=nz;  nznn=nz;
	       nznz=nz;   nzzn=nz;
	       if(trueval_setchar==1)
	       { nzz=set_sec_lwr_inc(4);
		 nzzz=set_sec_upr_inc(4);
		 if(trueval_setchar2==1)
		 { nzn=tert_set_lwr_inc(4);
		   nznn=tert_set_upr_inc(4);
		   nznz=quad_set_lwr_inc(4);
		   nzzn=quad_set_upr_inc(4);
		 }
	       }
	       for (n,nzz,nzn,nznz;n<=nz||nzz<=nzzz||nzn<=nznn||nznz<=nzzn;++nzn,++nznz,++nzz,++n)
	       { charassign(n,4);
		 myfile<<::password<<endl;
		 if(trueval_setchar==1)
		 { charassign(nzz,4);
		   myfile<<::password<<endl;
		   if(trueval_setchar2==1)
		   { charassign(nzn,4);
		     myfile<<::password<<endl;
		     charassign(nznz,4);
		     myfile<<::password<<endl;
		   }
		 }
		 int m,mz,mzz,mzzz,mzm,mzmm,mzmz,mzzm;
		 m=set_lwr_inc(5);
		 mz=set_upr_inc(5);
		 mzz=mz;    mzm=mz;
		 mzzz=mz;   mzmm=mz;
		 mzmz=mz;   mzzm=mz;
		 if(trueval_setchar==1)
		 { mzz=set_sec_lwr_inc(5);
		   mzzz=set_sec_upr_inc(5);
		   if(trueval_setchar2==1)
		   { mzm=tert_set_lwr_inc(5);
		     mzmm=tert_set_upr_inc(5);
		     mzmz=quad_set_lwr_inc(5);
		     mzzm=quad_set_upr_inc(5);
		   }
		 }
		 for(m,mzz,mzm,mzmz;m<=mz||mzz<=mzzz||mzm<=mzmm,mzmz<=mzzm;++m,++mzz,++mzm,++mzmz)
		 { charassign(m,5);
		   myfile<<::password<<endl;
		   if(trueval_setchar==1)
		   { charassign(mzz,5);
		     myfile<<::password<<endl;
		     if(trueval_setchar2==1)
		     { charassign(mzm,5);
		       myfile<<::password<<endl;
		       charassign(mzmz,5);
		       myfile<<::password<<endl;
		     }
		   }
		   int j,jz,jzz,jzzz,jzj,jzjj,jzjz,jzzj;
		   j=set_lwr_inc(6);
		   jz=set_upr_inc(6);
		   jzz=jz;       jzj=jz;
		   jzzz=jz;     jzjj=jz;
		   jzjz=jz;     jzzj=jz;
		   if(trueval_setchar==1)
		   { jzz=set_sec_lwr_inc(6);
		     jzzz=set_sec_upr_inc(6);
		     if(trueval_setchar2==1)
		     { jzj=tert_set_lwr_inc(6);
		       jzjj=tert_set_upr_inc(6);
		       jzjz=quad_set_lwr_inc(6);
		       jzzj=quad_set_upr_inc(6);
		     }
		   }
		   for(j,jzz,jzj,jzjz;j<=jz||jzz<=jzzz||jzj<=jzjj||jzjz<=jzzj;++j,++jzz,++jzj,++jzjz)
		   { charassign(j,6);
		     myfile<<::password<<endl;
		     if(trueval_setchar==1)
		     { charassign(jzz,6);
		       myfile<<::password<<endl;
		       if(trueval_setchar2==1)
		       { charassign(jzj,6);
			 myfile<<::password<<endl;
			 charassign(jzjz,6);
			 myfile<<::password<<endl;
		       }
		     }
		     int aa,aaz,aazz,aazzz,qz,qzz,qzq,qzqz;
		     aa=set_lwr_inc(7);
		     aaz=set_upr_inc(7);
		     azz=aaz;     qz=aaz;
		     aazzz=aaz;   qzz=aaz;
		     qzq=aaz;     qzqz=aaz;
		     if(trueval_setchar==1)
		     { aazz=set_sec_lwr_inc(7);
		       aazzz=set_sec_upr_inc(7);
		       if(trueval_setchar2==1)
		       { qz=tert_set_lwr_inc(7);
			 qzz=tert_set_upr_inc(7);
			 qzq=quad_set_lwr_inc(7);
			 qzqz=quad_set_upr_inc(7);
		       }
		     }
		     for(aa,aazz,qz,qzq;aa<=aaz||aazz<=aazzz||qz<=qzz||qzq<=qzqz;++aa,++aazz,++qz,++qzq)
		     { charassign(aa,7);
		       myfile<<::password<<endl;
		       if(trueval_setchar==1)
		       { charassign(aazz,7);
			 myfile<<::password<<endl;
			 if(trueval_setchar2==1)
			 { charassign(qz,7);
			   myfile<<::password<<endl;
			   charassign(qzq,7);
			   myfile<<::password<<endl;
			 }
		       }
		       int bb,bbz,bbzz,bbzzz,wz,wzz,wzw,wzzw;
		       bb=set_lwr_inc(8);
		       bbz=set_upr_inc(8);
		       bbzz=bbz;     wz=bbz;
		       bbzzz=bbz;    wzz=bbz;
		       wzw=bbz;      wzzw=bbz;
		       if(trueval_setchar==1)
		       { bbzz=set_sec_lwr_inc(8);
			 bbzzz=set_sec_upr_inc(8);
			 if(trueval_setchar2==1)
			  { wz=tert_set_lwr_inc(8);
			    wzz=tert_set_upr_inc(8);
			    wzw=quad_set_lwr_inc(8);
			    wzzw=quad_set_upr_inc(8);
			  }
		       }
		       for(bb,bbzz,wz,wzw;bb<=bbz||bbzz<=bbzzz||wz<=wzz||wzw<=wzzw;++bb,++bbzz,++wz,++wzw)
		       { charassign(bb,8);
			 myfile<<::password<<endl;
			 if(trueval_setchar==1)
			 { charassign(bbzz,8);
			   myfile<<::password<<endl;
			   if(trueval_setchar2==1)
			   { charassign(wz,8);
			     myfile<<::password<<endl;
			     charassign(wzw,8);
			     myfile<<::password<<endl;
			   }
			 }
		       }
		     }
		   }
		 }
	       }
	     }
	   }
	 }
       }
     }
     if(i==8)
      { initiate();
       int a,az,azz,azzz,aza,azaa,azaz,azza;
       a=set_lwr_inc(0);
       az=set_upr_inc(0);
       azz=az; 	azzz=az;
       aza=az;  azaa=az;
       azaz=az; azza=az;
       if(::trueval_setchar==1)
       { azz=set_sec_lwr_inc(0);
	 azzz=set_sec_upr_inc(0);
	 if(::trueval_setchar2==1)
	 { aza=tert_set_lwr_inc(0);
	   azaa=tert_set_upr_inc(0);
	   azaz=quad_set_lwr_inc(0);
	   azza=quad_set_upr_inc(0);
	 }
       }
       for(a,azz,azaz,aza;a<=az||azz<=azzz||aza<=azaa||azaz<=azza;++a,++aza,++azaz,++azz)
       { charassign(a,0);
	 myfile<<::password<<endl;
	 if(trueval_setchar==1)
	 { charassign(azz,0);
	   myfile<<::password<<endl;
	   if(trueval_setchar2==1)
	   {  charassign(aza,0);
	      myfile<<::password<<endl;
	      charassign(azaz,0);
	      myfile<<::password<<endl;
	   }
	 }
	 int c,cz,czz,czzz,czc,czcc,czcz,czzc;
	 c=set_lwr_inc(1);
	 cz=set_upr_inc(1);
	 czz=cz;   czzz=cz;
	 czc=cz;   czcc=cz;
	 czcz=cz;  czzc=cz;
	 if(trueval_setchar==1)
	 { czz=set_sec_lwr_inc(1);
	   czzz=set_sec_upr_inc(1);
	   if(trueval_setchar2==1)
	   { czc=tert_set_lwr_inc(1);
	     czcc=tert_set_upr_inc(1);
	     czcz=quad_set_lwr_inc(1);
	     czzc=quad_set_upr_inc(1);
	   }
	 }
	 for(c,czz,czc,czcz;c<=cz||czz<=czzz||czc<=czcc||czcz<=czzc;++c,++czz,++czc,++czcz)
	 { charassign(c,1);
	   myfile<<::password<<endl;
	   if(trueval_setchar==1)
	   { charassign(czz,1);
	     myfile<<::password<<endl;
	     if(trueval_setchar2==1)
	     {  charassign(czc,1);
		myfile<<::password<<endl;
		charassign(czcz,1);
		myfile<<::password<<endl;
	     }
	   }
	   int v,vz,vzz,vzzz,vzv,vzvv,vzvz,vzzv;
	   v=set_lwr_inc(2);
	   vz=set_upr_inc(2);
	   vzz=vz;    vzzz=vzz;
	   vzv=vz;    vzvv=vz;
	   vzvz=vz;   vzzv=vz;
	   if(trueval_setchar==1)
	   { vzz=set_sec_lwr_inc(2);
	     vzzz=set_sec_upr_inc(2);
	     if(trueval_setchar2==1)
	     { vzv=tert_set_lwr_inc(2);
	       vzvv=tert_set_upr_inc(2);
	       vzvz=quad_set_lwr_inc(2);
	       vzzv=quad_set_upr_inc(2);
	     }
	   }
	   for(v,vzz,vzv,vzvz;v<=vz||vzz<=vzzz||vzv<=vzvv||vzvz<=vzzv;++v,++vzz,++vzv,++vzvz)
	   { charassign(v,2);
	     myfile<<::password<<endl;
	     if(trueval_setchar==1)
	     { charassign(vzz,2);
	       myfile<<::password<<endl;
	       if(trueval_setchar2==1)
	       { charassign(vzv,2);
		 myfile<<::password<<endl;
		 charassign(vzvz,2);
		 myfile<<::password<<endl;
	       }
	     }
	     int b,bz,bzz,bzzz,bzb,bzbb,bzbz,bzzb;
	     b=set_lwr_inc(3);
	     bz=set_upr_inc(3);
	     bzz=bz;	bzb=bz;
	     bzzz=bz;  bzbb=bz;
	     bzbz=bz;   bzzb=bz;
	     if(trueval_setchar==1)
	     { bzz=set_sec_lwr_inc(3);
	       bzzz=set_sec_upr_inc(3);
	       if(trueval_setchar2==1)
	       { bzb=tert_set_lwr_inc(3);
		 bzbb=tert_set_upr_inc(3);
		 bzbz=quad_set_lwr_inc(3);
		 bzzb=quad_set_upr_inc(3);
	       }
	     }
	     for(b,bzz,bzb,bzbz;b<=bz||bzb<=bzbb||bzz<=bzzz||bzbz<=bzzb;++b,++bzb,++bzz,++bzbz)
	     { charassign(b,3);
	       myfile<<::password<<endl;
	       if(trueval_setchar==1)
	       { charassign(bzz,3);
		 myfile<<::password<<endl;
		 if(trueval_setchar2==1)
		 { charassign(bzb,3);
		   myfile<<::password<<endl;
		   charassign(bzbz,3);
		   myfile<<::password<<endl;
		 }
	       }
	       int n,nz,nzz,nzzz,nzn,nznn,nzzn,nznz;
	       n=set_lwr_inc(4);
	       nz=set_upr_inc(4);
	       nzz=nz;	  nzn=nz;
	       nzzz=nz;  nznn=nz;
	       nznz=nz;   nzzn=nz;
	       if(trueval_setchar==1)
	       { nzz=set_sec_lwr_inc(4);
		 nzzz=set_sec_upr_inc(4);
		 if(trueval_setchar2==1)
		 { nzn=tert_set_lwr_inc(4);
		   nznn=tert_set_upr_inc(4);
		   nznz=quad_set_lwr_inc(4);
		   nzzn=quad_set_upr_inc(4);
		 }
	       }
	       for (n,nzz,nzn,nznz;n<=nz||nzz<=nzzz||nzn<=nznn||nznz<=nzzn;++nzn,++nznz,++nzz,++n)
	       { charassign(n,4);
		 myfile<<::password<<endl;
		 if(trueval_setchar==1)
		 { charassign(nzz,4);
		   myfile<<::password<<endl;
		   if(trueval_setchar2==1)
		   { charassign(nzn,4);
		     myfile<<::password<<endl;
		     charassign(nznz,4);
		     myfile<<::password<<endl;
		   }
		 }
		 int m,mz,mzz,mzzz,mzm,mzmm,mzmz,mzzm;
		 m=set_lwr_inc(5);
		 mz=set_upr_inc(5);
		 mzz=mz;    mzm=mz;
		 mzzz=mz;   mzmm=mz;
		 mzmz=mz;   mzzm=mz;
		 if(trueval_setchar==1)
		 { mzz=set_sec_lwr_inc(5);
		   mzzz=set_sec_upr_inc(5);
		   if(trueval_setchar2==1)
		   { mzm=tert_set_lwr_inc(5);
		     mzmm=tert_set_upr_inc(5);
		     mzmz=quad_set_lwr_inc(5);
		     mzzm=quad_set_upr_inc(5);
		   }
		 }
		 for(m,mzz,mzm,mzmz;m<=mz||mzz<=mzzz||mzm<=mzmm,mzmz<=mzzm;++m,++mzz,++mzm,++mzmz)
		 { charassign(m,5);
		   myfile<<::password<<endl;
		   if(trueval_setchar==1)
		   { charassign(mzz,5);
		     myfile<<::password<<endl;
		     if(trueval_setchar2==1)
		     { charassign(mzm,5);
		       myfile<<::password<<endl;
		       charassign(mzmz,5);
		       myfile<<::password<<endl;
		     }
		   }
		   int j,jz,jzz,jzzz,jzj,jzjj,jzjz,jzzj;
		   j=set_lwr_inc(6);
		   jz=set_upr_inc(6);
		   jzz=jz;       jzj=jz;
		   jzzz=jz;     jzjj=jz;
		   jzjz=jz;     jzzj=jz;
		   if(trueval_setchar==1)
		   { jzz=set_sec_lwr_inc(6);
		     jzzz=set_sec_upr_inc(6);
		     if(trueval_setchar2==1)
		     { jzj=tert_set_lwr_inc(6);
		       jzjj=tert_set_upr_inc(6);
		       jzjz=quad_set_lwr_inc(6);
		       jzzj=quad_set_upr_inc(6);
		     }
		   }
		   for(j,jzz,jzj,jzjz;j<=jz||jzz<=jzzz||jzj<=jzjj||jzjz<=jzzj;++j,++jzz,++jzj,++jzjz)
		   { charassign(j,6);
		     myfile<<::password<<endl;
		     if(trueval_setchar==1)
		     { charassign(jzz,6);
		       myfile<<::password<<endl;
		       if(trueval_setchar2==1)
		       { charassign(jzj,6);
			 myfile<<::password<<endl;
			 charassign(jzjz,6);
			 myfile<<::password<<endl;
		       }
		     }
		     int aa,aaz,aazz,aazzz,qz,qzz,qzq,qzqz;
		     aa=set_lwr_inc(7);
		     aaz=set_upr_inc(7);
		     azz=aaz;     qz=aaz;
		     aazzz=aaz;   qzz=aaz;
		     qzq=aaz;     qzqz=aaz;
		     if(trueval_setchar==1)
		     { aazz=set_sec_lwr_inc(7);
		       aazzz=set_sec_upr_inc(7);
		       if(trueval_setchar2==1)
		       { qz=tert_set_lwr_inc(7);
			 qzz=tert_set_upr_inc(7);
			 qzq=quad_set_lwr_inc(7);
			 qzqz=quad_set_upr_inc(7);
		       }
		     }
		     for(aa,aazz,qz,qzq;aa<=aaz||aazz<=aazzz||qz<=qzz||qzq<=qzqz;++aa,++aazz,++qz,++qzq)
		     { charassign(aa,7);
		       myfile<<::password<<endl;
		       if(trueval_setchar==1)
		       { charassign(aazz,7);
			 myfile<<::password<<endl;
			 if(trueval_setchar2==1)
			 { charassign(qz,7);
			   myfile<<::password<<endl;
			   charassign(qzq,7);
			   myfile<<::password<<endl;
			 }
		       }
		     }
		   }
		 }
	       }
	     }
	   }
	 }
       }
     }
     if(i==7)
      { initiate();
       int a,az,azz,azzz,aza,azaa,azaz,azza;
       a=set_lwr_inc(0);
       az=set_upr_inc(0);
       azz=az; 	azzz=az;
       aza=az;  azaa=az;
       azaz=az; azza=az;
       if(::trueval_setchar==1)
       { azz=set_sec_lwr_inc(0);
	 azzz=set_sec_upr_inc(0);
	 if(::trueval_setchar2==1)
	 { aza=tert_set_lwr_inc(0);
	   azaa=tert_set_upr_inc(0);
	   azaz=quad_set_lwr_inc(0);
	   azza=quad_set_upr_inc(0);
	 }
       }
       for(a,azz,azaz,aza;a<=az||azz<=azzz||aza<=azaa||azaz<=azza;++a,++aza,++azaz,++azz)
       { charassign(a,0);
	 myfile<<::password<<endl;
	 if(trueval_setchar==1)
	 { charassign(azz,0);
	   myfile<<::password<<endl;
	   if(trueval_setchar2==1)
	   {  charassign(aza,0);
	      myfile<<::password<<endl;
	      charassign(azaz,0);
	      myfile<<::password<<endl;
	   }
	 }
	 int c,cz,czz,czzz,czc,czcc,czcz,czzc;
	 c=set_lwr_inc(1);
	 cz=set_upr_inc(1);
	 czz=cz;   czzz=cz;
	 czc=cz;   czcc=cz;
	 czcz=cz;  czzc=cz;
	 if(trueval_setchar==1)
	 { czz=set_sec_lwr_inc(1);
	   czzz=set_sec_upr_inc(1);
	   if(trueval_setchar2==1)
	   { czc=tert_set_lwr_inc(1);
	     czcc=tert_set_upr_inc(1);
	     czcz=quad_set_lwr_inc(1);
	     czzc=quad_set_upr_inc(1);
	   }
	 }
	 for(c,czz,czc,czcz;c<=cz||czz<=czzz||czc<=czcc||czcz<=czzc;++c,++czz,++czc,++czcz)
	 { charassign(c,1);
	   myfile<<::password<<endl;
	   if(trueval_setchar==1)
	   { charassign(czz,1);
	     myfile<<::password<<endl;
	     if(trueval_setchar2==1)
	     {  charassign(czc,1);
		myfile<<::password<<endl;
		charassign(czcz,1);
		myfile<<::password<<endl;
	     }
	   }
	   int v,vz,vzz,vzzz,vzv,vzvv,vzvz,vzzv;
	   v=set_lwr_inc(2);
	   vz=set_upr_inc(2);
	   vzz=vz;    vzzz=vzz;
	   vzv=vz;    vzvv=vz;
	   vzvz=vz;   vzzv=vz;
	   if(trueval_setchar==1)
	   { vzz=set_sec_lwr_inc(2);
	     vzzz=set_sec_upr_inc(2);
	     if(trueval_setchar2==1)
	     { vzv=tert_set_lwr_inc(2);
	       vzvv=tert_set_upr_inc(2);
	       vzvz=quad_set_lwr_inc(2);
	       vzzv=quad_set_upr_inc(2);
	     }
	   }
	   for(v,vzz,vzv,vzvz;v<=vz||vzz<=vzzz||vzv<=vzvv||vzvz<=vzzv;++v,++vzz,++vzv,++vzvz)
	   { charassign(v,2);
	     myfile<<::password<<endl;
	     if(trueval_setchar==1)
	     { charassign(vzz,2);
	       myfile<<::password<<endl;
	       if(trueval_setchar2==1)
	       { charassign(vzv,2);
		 myfile<<::password<<endl;
		 charassign(vzvz,2);
		 myfile<<::password<<endl;
	       }
	     }
	     int b,bz,bzz,bzzz,bzb,bzbb,bzbz,bzzb;
	     b=set_lwr_inc(3);
	     bz=set_upr_inc(3);
	     bzz=bz;	bzb=bz;
	     bzzz=bz;  bzbb=bz;
	     bzbz=bz;   bzzb=bz;
	     if(trueval_setchar==1)
	     { bzz=set_sec_lwr_inc(3);
	       bzzz=set_sec_upr_inc(3);
	       if(trueval_setchar2==1)
	       { bzb=tert_set_lwr_inc(3);
		 bzbb=tert_set_upr_inc(3);
		 bzbz=quad_set_lwr_inc(3);
		 bzzb=quad_set_upr_inc(3);
	       }
	     }
	     for(b,bzz,bzb,bzbz;b<=bz||bzb<=bzbb||bzz<=bzzz||bzbz<=bzzb;++b,++bzb,++bzz,++bzbz)
	     { charassign(b,3);
	       myfile<<::password<<endl;
	       if(trueval_setchar==1)
	       { charassign(bzz,3);
		 myfile<<::password<<endl;
		 if(trueval_setchar2==1)
		 { charassign(bzb,3);
		   myfile<<::password<<endl;
		   charassign(bzbz,3);
		   myfile<<::password<<endl;
		 }
	       }
	       int n,nz,nzz,nzzz,nzn,nznn,nzzn,nznz;
	       n=set_lwr_inc(4);
	       nz=set_upr_inc(4);
	       nzz=nz;	  nzn=nz;
	       nzzz=nz;  nznn=nz;
	       nznz=nz;   nzzn=nz;
	       if(trueval_setchar==1)
	       { nzz=set_sec_lwr_inc(4);
		 nzzz=set_sec_upr_inc(4);
		 if(trueval_setchar2==1)
		 { nzn=tert_set_lwr_inc(4);
		   nznn=tert_set_upr_inc(4);
		   nznz=quad_set_lwr_inc(4);
		   nzzn=quad_set_upr_inc(4);
		 }
	       }
	       for (n,nzz,nzn,nznz;n<=nz||nzz<=nzzz||nzn<=nznn||nznz<=nzzn;++nzn,++nznz,++nzz,++n)
	       { charassign(n,4);
		 myfile<<::password<<endl;
		 if(trueval_setchar==1)
		 { charassign(nzz,4);
		   myfile<<::password<<endl;
		   if(trueval_setchar2==1)
		   { charassign(nzn,4);
		     myfile<<::password<<endl;
		     charassign(nznz,4);
		     myfile<<::password<<endl;
		   }
		 }
		 int m,mz,mzz,mzzz,mzm,mzmm,mzmz,mzzm;
		 m=set_lwr_inc(5);
		 mz=set_upr_inc(5);
		 mzz=mz;    mzm=mz;
		 mzzz=mz;   mzmm=mz;
		 mzmz=mz;   mzzm=mz;
		 if(trueval_setchar==1)
		 { mzz=set_sec_lwr_inc(5);
		   mzzz=set_sec_upr_inc(5);
		   if(trueval_setchar2==1)
		   { mzm=tert_set_lwr_inc(5);
		     mzmm=tert_set_upr_inc(5);
		     mzmz=quad_set_lwr_inc(5);
		     mzzm=quad_set_upr_inc(5);
		   }
		 }
		 for(m,mzz,mzm,mzmz;m<=mz||mzz<=mzzz||mzm<=mzmm,mzmz<=mzzm;++m,++mzz,++mzm,++mzmz)
		 { charassign(m,5);
		   myfile<<::password<<endl;
		   if(trueval_setchar==1)
		   { charassign(mzz,5);
		     myfile<<::password<<endl;
		     if(trueval_setchar2==1)
		     { charassign(mzm,5);
		       myfile<<::password<<endl;
		       charassign(mzmz,5);
		       myfile<<::password<<endl;
		     }
		   }
		   int j,jz,jzz,jzzz,jzj,jzjj,jzjz,jzzj;
		   j=set_lwr_inc(6);
		   jz=set_upr_inc(6);
		   jzz=jz;       jzj=jz;
		   jzzz=jz;     jzjj=jz;
		   jzjz=jz;     jzzj=jz;
		   if(trueval_setchar==1)
		   { jzz=set_sec_lwr_inc(6);
		     jzzz=set_sec_upr_inc(6);
		     if(trueval_setchar2==1)
		     { jzj=tert_set_lwr_inc(6);
		       jzjj=tert_set_upr_inc(6);
		       jzjz=quad_set_lwr_inc(6);
		       jzzj=quad_set_upr_inc(6);
		     }
		   }
		   for(j,jzz,jzj,jzjz;j<=jz||jzz<=jzzz||jzj<=jzjj||jzjz<=jzzj;++j,++jzz,++jzj,++jzjz)
		   { charassign(j,6);
		     myfile<<::password<<endl;
		     if(trueval_setchar==1)
		     { charassign(jzz,6);
		       myfile<<::password<<endl;
		       if(trueval_setchar2==1)
		       { charassign(jzj,6);
			 myfile<<::password<<endl;
			 charassign(jzjz,6);
			 myfile<<::password<<endl;
		       }
		     }
		   }
		 }
	       }
	     }
	   }
	 }
       }
     }
     if(i==6)
     { initiate();
       int a,az,azz,azzz,aza,azaa,azaz,azza;
       a=set_lwr_inc(0);
       az=set_upr_inc(0);
       azz=az; 	azzz=az;
       aza=az;  azaa=az;
       azaz=az; azza=az;
       if(::trueval_setchar==1)
       { azz=set_sec_lwr_inc(0);
	 azzz=set_sec_upr_inc(0);
	 if(::trueval_setchar2==1)
	 { aza=tert_set_lwr_inc(0);
	   azaa=tert_set_upr_inc(0);
	   azaz=quad_set_lwr_inc(0);
	   azza=quad_set_upr_inc(0);
	 }
       }
       for(a,azz,azaz,aza;a<=az||azz<=azzz||aza<=azaa||azaz<=azza;++a,++aza,++azaz,++azz)
       { charassign(a,0);
	 myfile<<::password<<endl;
	 if(trueval_setchar==1)
	 { charassign(azz,0);
	   myfile<<::password<<endl;
	   if(trueval_setchar2==1)
	   {  charassign(aza,0);
	      myfile<<::password<<endl;
	      charassign(azaz,0);
	      myfile<<::password<<endl;
	   }
	 }
	 int c,cz,czz,czzz,czc,czcc,czcz,czzc;
	 c=set_lwr_inc(1);
	 cz=set_upr_inc(1);
	 czz=cz;   czzz=cz;
	 czc=cz;   czcc=cz;
	 czcz=cz;  czzc=cz;
	 if(trueval_setchar==1)
	 { czz=set_sec_lwr_inc(1);
	   czzz=set_sec_upr_inc(1);
	   if(trueval_setchar2==1)
	   { czc=tert_set_lwr_inc(1);
	     czcc=tert_set_upr_inc(1);
	     czcz=quad_set_lwr_inc(1);
	     czzc=quad_set_upr_inc(1);
	   }
	 }
	 for(c,czz,czc,czcz;c<=cz||czz<=czzz||czc<=czcc||czcz<=czzc;++c,++czz,++czc,++czcz)
	 { charassign(c,1);
	   myfile<<::password<<endl;
	   if(trueval_setchar==1)
	   { charassign(czz,1);
	     myfile<<::password<<endl;
	     if(trueval_setchar2==1)
	     {  charassign(czc,1);
		myfile<<::password<<endl;
		charassign(czcz,1);
		myfile<<::password<<endl;
	     }
	   }
	   int v,vz,vzz,vzzz,vzv,vzvv,vzvz,vzzv;
	   v=set_lwr_inc(2);
	   vz=set_upr_inc(2);
	   vzz=vz;    vzzz=vzz;
	   vzv=vz;    vzvv=vz;
	   vzvz=vz;   vzzv=vz;
	   if(trueval_setchar==1)
	   { vzz=set_sec_lwr_inc(2);
	     vzzz=set_sec_upr_inc(2);
	     if(trueval_setchar2==1)
	     { vzv=tert_set_lwr_inc(2);
	       vzvv=tert_set_upr_inc(2);
	       vzvz=quad_set_lwr_inc(2);
	       vzzv=quad_set_upr_inc(2);
	     }
	   }
	   for(v,vzz,vzv,vzvz;v<=vz||vzz<=vzzz||vzv<=vzvv||vzvz<=vzzv;++v,++vzz,++vzv,++vzvz)
	   { charassign(v,2);
	     myfile<<::password<<endl;
	     if(trueval_setchar==1)
	     { charassign(vzz,2);
	       myfile<<::password<<endl;
	       if(trueval_setchar2==1)
	       { charassign(vzv,2);
		 myfile<<::password<<endl;
		 charassign(vzvz,2);
		 myfile<<::password<<endl;
	       }
	     }
	     int b,bz,bzz,bzzz,bzb,bzbb,bzbz,bzzb;
	     b=set_lwr_inc(3);
	     bz=set_upr_inc(3);
	     bzz=bz;	bzb=bz;
	     bzzz=bz;  bzbb=bz;
	     bzbz=bz;   bzzb=bz;
	     if(trueval_setchar==1)
	     { bzz=set_sec_lwr_inc(3);
	       bzzz=set_sec_upr_inc(3);
	       if(trueval_setchar2==1)
	       { bzb=tert_set_lwr_inc(3);
		 bzbb=tert_set_upr_inc(3);
		 bzbz=quad_set_lwr_inc(3);
		 bzzb=quad_set_upr_inc(3);
	       }
	     }
	     for(b,bzz,bzb,bzbz;b<=bz||bzb<=bzbb||bzz<=bzzz||bzbz<=bzzb;++b,++bzb,++bzz,++bzbz)
	     { charassign(b,3);
	       myfile<<::password<<endl;
	       if(trueval_setchar==1)
	       { charassign(bzz,3);
		 myfile<<::password<<endl;
		 if(trueval_setchar2==1)
		 { charassign(bzb,3);
		   myfile<<::password<<endl;
		   charassign(bzbz,3);
		   myfile<<::password<<endl;
		 }
	       }
	       int n,nz,nzz,nzzz,nzn,nznn,nzzn,nznz;
	       n=set_lwr_inc(4);
	       nz=set_upr_inc(4);
	       nzz=nz;	  nzn=nz;
	       nzzz=nz;  nznn=nz;
	       nznz=nz;   nzzn=nz;
	       if(trueval_setchar==1)
	       { nzz=set_sec_lwr_inc(4);
		 nzzz=set_sec_upr_inc(4);
		 if(trueval_setchar2==1)
		 { nzn=tert_set_lwr_inc(4);
		   nznn=tert_set_upr_inc(4);
		   nznz=quad_set_lwr_inc(4);
		   nzzn=quad_set_upr_inc(4);
		 }
	       }
	       for (n,nzz,nzn,nznz;n<=nz||nzz<=nzzz||nzn<=nznn||nznz<=nzzn;++nzn,++nznz,++nzz,++n)
	       { charassign(n,4);
		 myfile<<::password<<endl;
		 if(trueval_setchar==1)
		 { charassign(nzz,4);
		   myfile<<::password<<endl;
		   if(trueval_setchar2==1)
		   { charassign(nzn,4);
		     myfile<<::password<<endl;
		     charassign(nznz,4);
		     myfile<<::password<<endl;
		   }
		 }
		 int m,mz,mzz,mzzz,mzm,mzmm,mzmz,mzzm;
		 m=set_lwr_inc(5);
		 mz=set_upr_inc(5);
		 mzz=mz;    mzm=mz;
		 mzzz=mz;   mzmm=mz;
		 mzmz=mz;   mzzm=mz;
		 if(trueval_setchar==1)
		 { mzz=set_sec_lwr_inc(5);
		   mzzz=set_sec_upr_inc(5);
		   if(trueval_setchar2==1)
		   { mzm=tert_set_lwr_inc(5);
		     mzmm=tert_set_upr_inc(5);
		     mzmz=quad_set_lwr_inc(5);
		     mzzm=quad_set_upr_inc(5);
		   }
		 }
		 for(m,mzz,mzm,mzmz;m<=mz||mzz<=mzzz||mzm<=mzmm,mzmz<=mzzm;++m,++mzz,++mzm,++mzmz)
		 { charassign(m,5);
		   myfile<<::password<<endl;
		   if(trueval_setchar==1)
		   { charassign(mzz,5);
		     myfile<<::password<<endl;
		     if(trueval_setchar2==1)
		     { charassign(mzm,5);
		       myfile<<::password<<endl;
		       charassign(mzmz,5);
		       myfile<<::password<<endl;
		     }
		   }
		 }
	       }
	     }
	   }
	 }
       }
     }
     if(i==5)
      { initiate();
       int a,az,azz,azzz,aza,azaa,azaz,azza;
       a=set_lwr_inc(0);
       az=set_upr_inc(0);
       azz=az; 	azzz=az;
       aza=az;  azaa=az;
       azaz=az; azza=az;
       if(::trueval_setchar==1)
       { azz=set_sec_lwr_inc(0);
	 azzz=set_sec_upr_inc(0);
	 if(::trueval_setchar2==1)
	 { aza=tert_set_lwr_inc(0);
	   azaa=tert_set_upr_inc(0);
	   azaz=quad_set_lwr_inc(0);
	   azza=quad_set_upr_inc(0);
	 }
       }
       for(a,azz,azaz,aza;a<=az||azz<=azzz||aza<=azaa||azaz<=azza;++a,++aza,++azaz,++azz)
       { charassign(a,0);
	 myfile<<::password<<endl;
	 if(trueval_setchar==1)
	 { charassign(azz,0);
	   myfile<<::password<<endl;
	   if(trueval_setchar2==1)
	   {  charassign(aza,0);
	      myfile<<::password<<endl;
	      charassign(azaz,0);
	      myfile<<::password<<endl;
	   }
	 }
	 int c,cz,czz,czzz,czc,czcc,czcz,czzc;
	 c=set_lwr_inc(1);
	 cz=set_upr_inc(1);
	 czz=cz;   czzz=cz;
	 czc=cz;   czcc=cz;
	 czcz=cz;  czzc=cz;
	 if(trueval_setchar==1)
	 { czz=set_sec_lwr_inc(1);
	   czzz=set_sec_upr_inc(1);
	   if(trueval_setchar2==1)
	   { czc=tert_set_lwr_inc(1);
	     czcc=tert_set_upr_inc(1);
	     czcz=quad_set_lwr_inc(1);
	     czzc=quad_set_upr_inc(1);
	   }
	 }
	 for(c,czz,czc,czcz;c<=cz||czz<=czzz||czc<=czcc||czcz<=czzc;++c,++czz,++czc,++czcz)
	 { charassign(c,1);
	   myfile<<::password<<endl;
	   if(trueval_setchar==1)
	   { charassign(czz,1);
	     myfile<<::password<<endl;
	     if(trueval_setchar2==1)
	     {  charassign(czc,1);
		myfile<<::password<<endl;
		charassign(czcz,1);
		myfile<<::password<<endl;
	     }
	   }
	   int v,vz,vzz,vzzz,vzv,vzvv,vzvz,vzzv;
	   v=set_lwr_inc(2);
	   vz=set_upr_inc(2);
	   vzz=vz;    vzzz=vzz;
	   vzv=vz;    vzvv=vz;
	   vzvz=vz;   vzzv=vz;
	   if(trueval_setchar==1)
	   { vzz=set_sec_lwr_inc(2);
	     vzzz=set_sec_upr_inc(2);
	     if(trueval_setchar2==1)
	     { vzv=tert_set_lwr_inc(2);
	       vzvv=tert_set_upr_inc(2);
	       vzvz=quad_set_lwr_inc(2);
	       vzzv=quad_set_upr_inc(2);
	     }
	   }
	   for(v,vzz,vzv,vzvz;v<=vz||vzz<=vzzz||vzv<=vzvv||vzvz<=vzzv;++v,++vzz,++vzv,++vzvz)
	   { charassign(v,2);
	     myfile<<::password<<endl;
	     if(trueval_setchar==1)
	     { charassign(vzz,2);
	       myfile<<::password<<endl;
	       if(trueval_setchar2==1)
	       { charassign(vzv,2);
		 myfile<<::password<<endl;
		 charassign(vzvz,2);
		 myfile<<::password<<endl;
	       }
	     }
	     int b,bz,bzz,bzzz,bzb,bzbb,bzbz,bzzb;
	     b=set_lwr_inc(3);
	     bz=set_upr_inc(3);
	     bzz=bz;	bzb=bz;
	     bzzz=bz;  bzbb=bz;
	     bzbz=bz;   bzzb=bz;
	     if(trueval_setchar==1)
	     { bzz=set_sec_lwr_inc(3);
	       bzzz=set_sec_upr_inc(3);
	       if(trueval_setchar2==1)
	       { bzb=tert_set_lwr_inc(3);
		 bzbb=tert_set_upr_inc(3);
		 bzbz=quad_set_lwr_inc(3);
		 bzzb=quad_set_upr_inc(3);
	       }
	     }
	     for(b,bzz,bzb,bzbz;b<=bz||bzb<=bzbb||bzz<=bzzz||bzbz<=bzzb;++b,++bzb,++bzz,++bzbz)
	     { charassign(b,3);
	       myfile<<::password<<endl;
	       if(trueval_setchar==1)
	       { charassign(bzz,3);
		 myfile<<::password<<endl;
		 if(trueval_setchar2==1)
		 { charassign(bzb,3);
		   myfile<<::password<<endl;
		   charassign(bzbz,3);
		   myfile<<::password<<endl;
		 }
	       }
	       int n,nz,nzz,nzzz,nzn,nznn,nzzn,nznz;
	       n=set_lwr_inc(4);
	       nz=set_upr_inc(4);
	       nzz=nz;	  nzn=nz;
	       nzzz=nz;  nznn=nz;
	       nznz=nz;   nzzn=nz;
	       if(trueval_setchar==1)
	       { nzz=set_sec_lwr_inc(4);
		 nzzz=set_sec_upr_inc(4);
		 if(trueval_setchar2==1)
		 { nzn=tert_set_lwr_inc(4);
		   nznn=tert_set_upr_inc(4);
		   nznz=quad_set_lwr_inc(4);
		   nzzn=quad_set_upr_inc(4);
		 }
	       }
	       for (n,nzz,nzn,nznz;n<=nz||nzz<=nzzz||nzn<=nznn||nznz<=nzzn;++nzn,++nznz,++nzz,++n)
	       { charassign(n,4);
		 myfile<<::password<<endl;
		 if(trueval_setchar==1)
		 { charassign(nzz,4);
		   myfile<<::password<<endl;
		   if(trueval_setchar2==1)
		   { charassign(nzn,4);
		     myfile<<::password<<endl;
		     charassign(nznz,4);
		     myfile<<::password<<endl;
		   }
		 }
	       }
	     }
	   }
	 }
       }
     }
     if(i==4)
     { initiate();
       int a,az,azz,azzz,aza,azaa,azaz,azza;
       a=set_lwr_inc(0);
       az=set_upr_inc(0);
       azz=az; 	azzz=az;
       aza=az;  azaa=az;
       azaz=az; azza=az;
       if(::trueval_setchar==1)
       { azz=set_sec_lwr_inc(0);
	 azzz=set_sec_upr_inc(0);
	 if(::trueval_setchar2==1)
	 { aza=tert_set_lwr_inc(0);
	   azaa=tert_set_upr_inc(0);
	   azaz=quad_set_lwr_inc(0);
	   azza=quad_set_upr_inc(0);
	 }
       }
       for(a,azz,azaz,aza;a<=az||azz<=azzz||aza<=azaa||azaz<=azza;++a,++aza,++azaz,++azz)
       { charassign(a,0);
	 myfile<<::password<<endl;
	 if(trueval_setchar==1)
	 { charassign(azz,0);
	   myfile<<::password<<endl;
	   if(trueval_setchar2==1)
	   {  charassign(aza,0);
	      myfile<<::password<<endl;
	      charassign(azaz,0);
	      myfile<<::password<<endl;
	   }
	 }
	 int c,cz,czz,czzz,czc,czcc,czcz,czzc;
	 c=set_lwr_inc(1);
	 cz=set_upr_inc(1);
	 czz=cz;   czzz=cz;
	 czc=cz;   czcc=cz;
	 czcz=cz;  czzc=cz;
	 if(trueval_setchar==1)
	 { czz=set_sec_lwr_inc(1);
	   czzz=set_sec_upr_inc(1);
	   if(trueval_setchar2==1)
	   { czc=tert_set_lwr_inc(1);
	     czcc=tert_set_upr_inc(1);
	     czcz=quad_set_lwr_inc(1);
	     czzc=quad_set_upr_inc(1);
	   }
	 }
	 for(c,czz,czc,czcz;c<=cz||czz<=czzz||czc<=czcc||czcz<=czzc;++c,++czz,++czc,++czcz)
	 { charassign(c,1);
	   myfile<<::password<<endl;
	   if(trueval_setchar==1)
	   { charassign(czz,1);
	     myfile<<::password<<endl;
	     if(trueval_setchar2==1)
	     {  charassign(czc,1);
		myfile<<::password<<endl;
		charassign(czcz,1);
		myfile<<::password<<endl;
	     }
	   }
	   int v,vz,vzz,vzzz,vzv,vzvv,vzvz,vzzv;
	   v=set_lwr_inc(2);
	   vz=set_upr_inc(2);
	   vzz=vz;    vzzz=vzz;
	   vzv=vz;    vzvv=vz;
	   vzvz=vz;   vzzv=vz;
	   if(trueval_setchar==1)
	   { vzz=set_sec_lwr_inc(2);
	     vzzz=set_sec_upr_inc(2);
	     if(trueval_setchar2==1)
	     { vzv=tert_set_lwr_inc(2);
	       vzvv=tert_set_upr_inc(2);
	       vzvz=quad_set_lwr_inc(2);
	       vzzv=quad_set_upr_inc(2);
	     }
	   }
	   for(v,vzz,vzv,vzvz;v<=vz||vzz<=vzzz||vzv<=vzvv||vzvz<=vzzv;++v,++vzz,++vzv,++vzvz)
	   { charassign(v,2);
	     myfile<<::password<<endl;
	     if(trueval_setchar==1)
	     { charassign(vzz,2);
	       myfile<<::password<<endl;
	       if(trueval_setchar2==1)
	       { charassign(vzv,2);
		 myfile<<::password<<endl;
		 charassign(vzvz,2);
		 myfile<<::password<<endl;
	       }
	     }
	     int b,bz,bzz,bzzz,bzb,bzbb,bzbz,bzzb;
	     b=set_lwr_inc(3);
	     bz=set_upr_inc(3);
	     bzz=bz;	bzb=bz;
	     bzzz=bz;  bzbb=bz;
	     bzbz=bz;   bzzb=bz;
	     if(trueval_setchar==1)
	     { bzz=set_sec_lwr_inc(3);
	       bzzz=set_sec_upr_inc(3);
	       if(trueval_setchar2==1)
	       { bzb=tert_set_lwr_inc(3);
		 bzbb=tert_set_upr_inc(3);
		 bzbz=quad_set_lwr_inc(3);
		 bzzb=quad_set_upr_inc(3);
	       }
	     }
	     for(b,bzz,bzb,bzbz;b<=bz||bzb<=bzbb||bzz<=bzzz||bzbz<=bzzb;++b,++bzb,++bzz,++bzbz)
	     { charassign(b,3);
	       myfile<<::password<<endl;
	       if(trueval_setchar==1)
	       { charassign(bzz,3);
		 myfile<<::password<<endl;
		 if(trueval_setchar2==1)
		 { charassign(bzb,3);
		   myfile<<::password<<endl;
		   charassign(bzbz,3);
		   myfile<<::password<<endl;
		 }
	       }
	     }
	   }
	 }
       }
     }
     if(i==3)
     { initiate();
       int a,az,azz,azzz,aza,azaa,azaz,azza;
       a=set_lwr_inc(0);
       az=set_upr_inc(0);
       azz=az; 	azzz=az;
       aza=az;  azaa=az;
       azaz=az; azza=az;
       if(::trueval_setchar==1)
       { azz=set_sec_lwr_inc(0);
	 azzz=set_sec_upr_inc(0);
	 if(::trueval_setchar2==1)
	 { aza=tert_set_lwr_inc(0);
	   azaa=tert_set_upr_inc(0);
	   azaz=quad_set_lwr_inc(0);
	   azza=quad_set_upr_inc(0);
	 }
       }
       for(a,azz,azaz,aza;a<=az||azz<=azzz||aza<=azaa||azaz<=azza;++a,++aza,++azaz,++azz)
       { charassign(a,0);
	 myfile<<::password<<endl;
	 if(trueval_setchar==1)
	 { charassign(azz,0);
	   myfile<<::password<<endl;
	   if(trueval_setchar2==1)
	   {  charassign(aza,0);
	      myfile<<::password<<endl;
	      charassign(azaz,0);
	      myfile<<::password<<endl;
	   }
	 }
	 int c,cz,czz,czzz,czc,czcc,czcz,czzc;
	 c=set_lwr_inc(1);
	 cz=set_upr_inc(1);
	 czz=cz;   czzz=cz;
	 czc=cz;   czcc=cz;
	 czcz=cz;  czzc=cz;
	 if(trueval_setchar==1)
	 { czz=set_sec_lwr_inc(1);
	   czzz=set_sec_upr_inc(1);
	   if(trueval_setchar2==1)
	   { czc=tert_set_lwr_inc(1);
	     czcc=tert_set_upr_inc(1);
	     czcz=quad_set_lwr_inc(1);
	     czzc=quad_set_upr_inc(1);
	   }
	 }
	 for(c,czz,czc,czcz;c<=cz||czz<=czzz||czc<=czcc||czcz<=czzc;++c,++czz,++czc,++czcz)
	 { charassign(c,1);
	   myfile<<::password<<endl;
	   if(trueval_setchar==1)
	   { charassign(czz,1);
	     myfile<<::password<<endl;
	     if(trueval_setchar2==1)
	     {  charassign(czc,1);
		myfile<<::password<<endl;
		charassign(czcz,1);
		myfile<<::password<<endl;
	     }
	   }
	   int v,vz,vzz,vzzz,vzv,vzvv,vzvz,vzzv;
	   v=set_lwr_inc(2);
	   vz=set_upr_inc(2);
	   vzz=vz;    vzzz=vzz;
	   vzv=vz;    vzvv=vz;
	   vzvz=vz;   vzzv=vz;
	   if(trueval_setchar==1)
	   { vzz=set_sec_lwr_inc(2);
	     vzzz=set_sec_upr_inc(2);
	     if(trueval_setchar2==1)
	     { vzv=tert_set_lwr_inc(2);
	       vzvv=tert_set_upr_inc(2);
	       vzvz=quad_set_lwr_inc(2);
	       vzzv=quad_set_upr_inc(2);
	     }
	   }
	   for(v,vzz,vzv,vzvz;v<=vz||vzz<=vzzz||vzv<=vzvv||vzvz<=vzzv;++v,++vzz,++vzv,++vzvz)
	   { charassign(v,2);
	     myfile<<::password<<endl;
	     if(trueval_setchar==1)
	     { charassign(vzz,2);
	       myfile<<::password<<endl;
	       if(trueval_setchar2==1)
	       { charassign(vzv,2);
		 myfile<<::password<<endl;
		 charassign(vzvz,2);
		 myfile<<::password<<endl;
	       }
	     }
	   }
	 }
       }
     }
     if(i==2)
     { initiate();
       int a,az,azz,azzz,aza,azaa,azaz,azza;
       a=set_lwr_inc(0);
       az=set_upr_inc(0);
       azz=az; 	azzz=az;
       aza=az;  azaa=az;
       azaz=az; azza=az;
       if(::trueval_setchar==1)
       { azz=set_sec_lwr_inc(0);
	 azzz=set_sec_upr_inc(0);
	 if(::trueval_setchar2==1)
	 { aza=tert_set_lwr_inc(0);
	   azaa=tert_set_upr_inc(0);
	   azaz=quad_set_lwr_inc(0);
	   azza=quad_set_upr_inc(0);
	 }
       }
       for(a,azz,azaz,aza;a<=az||azz<=azzz||aza<=azaa||azaz<=azza;++a,++aza,++azaz,++azz)
       { charassign(a,0);
	 myfile<<::password<<endl;
	 if(trueval_setchar==1)
	 { charassign(azz,0);
	   myfile<<::password<<endl;
	   if(trueval_setchar2==1)
	   {  charassign(aza,0);
	      myfile<<::password<<endl;
	      charassign(azaz,0);
	      myfile<<::password<<endl;
	   }
	 }
	 int c,cz,czz,czzz,czc,czcc,czcz,czzc;
	 c=set_lwr_inc(1);
	 cz=set_upr_inc(1);
	 czz=cz;   czzz=cz;
	 czc=cz;   czcc=cz;
	 czcz=cz;  czzc=cz;
	 if(trueval_setchar==1)
	 { czz=set_sec_lwr_inc(1);
	   czzz=set_sec_upr_inc(1);
	   if(trueval_setchar2==1)
	   { czc=tert_set_lwr_inc(1);
	     czcc=tert_set_upr_inc(1);
	     czcz=quad_set_lwr_inc(1);
	     czzc=quad_set_upr_inc(1);
	   }
	 }
	 for(c,czz,czc,czcz;c<=cz||czz<=czzz||czc<=czcc||czcz<=czzc;++c,++czz,++czc,++czcz)
	 { charassign(c,1);
	   myfile<<::password<<endl;
	   if(trueval_setchar==1)
	   { charassign(czz,1);
	     myfile<<::password<<endl;
	     if(trueval_setchar2==1)
	     {  charassign(czc,1);
		myfile<<::password<<endl;
		charassign(czcz,1);
		myfile<<::password<<endl;
	     }
	   }
	 }
       }
     }
     if(i==1)
     { initiate();
       int a,az,azz,azzz,aza,azaa,azaz,azza;
       a=set_lwr_inc(0);
       az=set_upr_inc(0);
       charassign(a,0);
       azz=az;	 aza=az;
       azzz=azz; azaa=az;
       azza=az;  azaz=az;
       if(::trueval_setchar==1)
       { azz=set_sec_lwr_inc(0);
	 azzz=set_sec_upr_inc(0);
	 if(::trueval_setchar2==1)
	 { aza=tert_set_lwr_inc(0);
	   azaa=tert_set_upr_inc(0);
	   azaz=quad_set_lwr_inc(0);
	   azza=quad_set_upr_inc(0);
	 }
       }
       for(a,azz,aza,azaz;azaz<=azza,a<=az||azz<=azzz||aza<=azaa;++a,++azz,++aza,++azaz)
       { charassign(a,0);
	 myfile<<::password<<endl;
	 if(::trueval_setchar==1)
	 { charassign(azz,0);
	   myfile<<::password<<endl;
	   if(::trueval_setchar2==1)
	   { charassign(aza,0);
	     myfile<<::password<<endl;
	     charassign(azaz,0);
	     myfile<<::password<<endl;
	   }
	 }
       }
     }
   }
}

void main ()
{ init();
  int a;
  clrscr ();
  a=confirmation();
  if(a==0)
    goto end;
  else
  { req();
    ::y=menu();
    if (::y==1)
    knownc();
    if(::y==1||::y==2)
      Brute();
  }
  end:
  getch();
}
void asthetics()
{ clrscr();
  cout<<"************************************BRUTE***************************************"<<endl;//Decoration
  cout<<endl<<endl;
  cout<<"\t\tcddddddddddddddddddddddddddddddddddddddddddd;"<<endl;
  cout<<"\t\t0Mo..........':ldkO0KKXXKK0kxoc,..........kMd"<<endl;
  cout<<"\t\t0Ml......;d0WMMMMMMMMMMMMMMMMMMMWKx:......kMd"<<endl;
  cout<<"\t\t0Ml...cOWMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:...kMd"<<endl;
  cout<<"\t\t0Ml.lNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNc.kMd"<<endl;
  cout<<"\t\t0MdKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0OMd"<<endl;
  cout<<"\t\t0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd"<<endl;
  cout<<"\t\t0MxcxWMMMMMNXXNMMMMMMMMMMMMMMMNXXNMMMMMWkcKMd"<<endl;
  cout<<"\t\t0Md..lMKo,.,'...:kWMMMMMMMNx;...',.;dXMl.'XMd"<<endl;
  cout<<"\t\t0Mx'.,O;dXMMMXl....:dWMNo;....oXMMMKd;0,.'KMd"<<endl;
  cout<<"\t\t0MO;.,NMWMMMMMMWk;...XMK...:OWMMMMMMWMN,.cNMd"<<endl;
  cout<<"\t\t0MxxNMX;KMMKdcclkWN0WMMMN0WNxc:lxXMMk;WMXdKMd"<<endl;
  cout<<"\t\t0MMMMMO;MMl.......KMXOMNkMk.......xMM.NMMMMMd"<<endl;
  cout<<"\t\t0MMMMMMXKoclddl;.oWMdkMN,MN:.:ldolcdXNMMMMMMd"<<endl;
  cout<<"\t\t0MMMMMMWXMMMMMMMW0KdoNMMdox0MMMMMMMMXMMMMMMMd"<<endl;
  cout<<"\t\t0MMMMXc'WMMMMMMMMkcWMMMMMMkcMMMMMMMMN'lXMMMMd"<<endl;
  cout<<"\t\t0MMMd..cMMMMMMMMNdoKMMMMM0x:XMMMMMMMM:..kMMMd"<<endl;
  cout<<"\t\t0MM0....d0KKOd:.....c0Kx'.....:d0NX0l....NMMd"<<endl;
  cout<<"\t\t0MMO.....................................WMMd"<<endl;
  cout<<"\t\t0Mdkc...................................0kOMd"<<endl;
  cout<<"\t\t0Ml.:Ol;........';;.......;,........':oX:.kMd"<<endl;
  cout<<"\t\t0Ml..,WMMMMWWWo...';;:c::;'...:WWMMMMMW;..kMd"<<endl;
  cout<<"\t\t0Ml...dMMMMMMMMKl...........c0MMMMMMMMd...kMd"<<endl;
  cout<<"\t\t0Ml...cMMMMMMMMMMMXOxdddk0NMMMMMMMMMMM'...kMd"<<endl;
  cout<<"\t\t0Ml....KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO....kMd"<<endl;
  cout<<"\t\t0Ml.....OMMMMMMMMMMMMMMMMMMMMMMMMMMMK.....kMd"<<endl;
  cout<<"\t\t0Ml......:XMMMMMMMMMMMMMMMMMMMMMMMNl......kMd"<<endl;
  cout<<"\t\t0Ml........lXMMMMMMMMMMMMMMMMMMMKc........kMd"<<endl;
  cout<<"\t\t0Ml..........:KMMMMMMMMMMMMMMM0,..........kMd"<<endl;
  cout<<"\t\toO:............xOOOx:'';dOOOOd............lOc"<<endl;

}