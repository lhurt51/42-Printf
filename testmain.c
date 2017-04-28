#include "printf.h"
#include <stdio.h>

int main()
{
	// wchar_t *str = L"Hello";

	// printf("PRINTF: Hello%-10lctest %ls *Kashim a � histoires à raconterIl fait au moins ��c\n", (wchar_t)0, str);
	// ft_printf("FT_PRINTF: Hello%-10lctest %ls *Kashim a � histoires à raconterIl fait au moins ��c\n", (wchar_t)0, str);
	// ft_printf("%c\n", 42);
	ft_printf("Kashim a %c histoires à raconter\n", 1001);
	ft_printf("Il fait au moins %c\n", -8000);
	ft_printf("%c\n", -0);
	ft_printf("%c\n", 0);
	// // ft_printf("%c\n", INT_MAX);
	ft_printf("%c\n", 'c');
	ft_printf("%c\n", '\n');
	ft_printf("%c\n", 'l');
	ft_printf("%c\n", 'y');
	ft_printf("%c\n", ' ');
	ft_printf("%c\n", 'e');
	ft_printf("%c\n", 's');
	ft_printf("%c\n", 't');
	ft_printf("%c\n", ' ');
	ft_printf("%c\n", 'f');
	ft_printf("%c\n", 'a');
	ft_printf("%c\n", 'n');
	ft_printf("%c\n", 't');
	ft_printf("%c\n", 'a');
	ft_printf("%c\n", 's');
	ft_printf("%c\n", 't');
	ft_printf("%c\n", 'i');
	ft_printf("%c\n", 'q');
	ft_printf("%c\n", 'u');
	ft_printf("%c\n", 'e');
	ft_printf("%c\n", '!');
	ft_printf("%c\n", '\r');
	ft_printf("%c\n", '\t');
	//
	// unsigned char a = -125;
	// unsigned int b = -125;
	// unsigned long c = -125;
	// unsigned short d = -125;
	// size_t e = -125;
	// uintmax_t f = -125;
	// unsigned long long	g = -125;
	//
	// unsigned char h = 0;
	// unsigned int i = 0;
	// unsigned long j = 0;
	// unsigned short k = 0;
	// size_t l = 0;
	// uintmax_t m = 0;
	// unsigned long long n = 0;
	//
	// unsigned char o = (unsigned char)~0U>>1;
	// unsigned int p = ~0U>>1;
	// unsigned long q = ~0U>>1;
	// unsigned short r = (short)~0U>>1;
	// size_t s = (size_t)~0U>>1;
	// uintmax_t t = (uintmax_t)~0U>>1;
	// unsigned long long u = (unsigned long long)~0U>>1;
	//
	// unsigned char v = -m-1;
	// unsigned int w = -n-1;
	// unsigned long x = -o-1;
	// unsigned short y = -p-1;
	// unsigned long z = -q-1;
	// uintmax_t zz = -r-1;
	// unsigned long long aa = -r-1;
	//
	// ft_printf("unsigned char		a = %hhu sizeof a = %lu\n", a,sizeof(a));
	// ft_printf("unsigned int		b = %u sizeof b = %lu\n",b,sizeof(b));
	// ft_printf("unsigned long		c = %lu sizeof c = %lu\n",c,sizeof(c));
	// ft_printf("unsigned short		d = %hu sizeof d = %lu\n",d,sizeof(d));
	// ft_printf("size_t			e = %zu sizeof e = %lu\n",e,sizeof(e));
	// ft_printf("uintmax_t		f = %ju sizeof f = %lu\n",f,sizeof(f));
	// ft_printf("unsigned long long	g = %llu sizeof g = %lu\n\n",g,sizeof(g));
	//
	// ft_printf("unsigned char		h = %hhu sizeof h = %lu\n", h,sizeof(h));
	// ft_printf("unsigned int		i = %u sizeof i = %lu\n",i,sizeof(i));
	// ft_printf("unsigned long		j = %lu sizeof j = %lu\n",j,sizeof(j));
	// ft_printf("unsigned short		k = %hu sizeof k = %lu\n",k,sizeof(k));
	// ft_printf("size_t			l = %zu sizeof l = %lu\n",l,sizeof(l));
	// ft_printf("uintmax_t		m = %ju sizeof m = %lu\n",m,sizeof(m));
	// ft_printf("unsigned long long	n = %llu sizeof n = %lu\n\n",n,sizeof(n));
	//
	// ft_printf("unsigned char		o = %hhu sizeof o = %lu\n", o,sizeof(o));
	// ft_printf("unsigned int		p = %u sizeof p = %lu\n",p,sizeof(p));
	// ft_printf("unsigned long		q = %lu sizeof q = %lu\n",q,sizeof(q));
	// ft_printf("unsigned short		r = %hu sizeof r = %lu\n",r,sizeof(r));
	// ft_printf("size_t			s = %zu sizeof s = %lu\n",s,sizeof(s));
	// ft_printf("uintmax_t		t = %ju sizeof t = %lu\n",t,sizeof(t));
	// ft_printf("unsigned long long	u = %llu sizeof u = %lu\n\n",u,sizeof(u));
	//
	// ft_printf("unsigned char		v = %hhu sizeof v = %lu\n", v,sizeof(v));
	// ft_printf("unsigned int		w = %u sizeof w = %lu\n",w,sizeof(w));
	// ft_printf("unsigned long		x = %lu sizeof x = %lu\n",x,sizeof(x));
	// ft_printf("unsigned short		y = %hu sizeof y = %lu\n",y,sizeof(y));
	// ft_printf("size_t			z = %zu sizeof z = %lu\n",z,sizeof(z));
	// ft_printf("uintmax_t		zz = %ju sizeof zz = %lu\n",zz,sizeof(zz));
	// ft_printf("unsigned long long	aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa));
	//
	// int			r00 = 0;

	// ft_printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p\n", 100, "Ly", &r00);
	// printf("%#15.8x\n", 3588976);
	ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");

	// ft_printf("%%+04d 42 == %0+04d\n", 42);

	// char		*str = NULL;
	//
	// ft_printf("%s", "pouet");
	// ft_printf(" pouet %s !!\n", "camembert");
	// ft_printf("%s !\n", "Ceci n'est pas un \0 exercice !");
	// ft_printf("%s!\n", "Ceci n'est toujours pas un exercice !");
	// ft_printf("%s!\n", str);
	// ft_printf("%s", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");
	return (1);
}
