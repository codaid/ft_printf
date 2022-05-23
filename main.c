#include <stdio.h>
#include "./ft_printf.h"

int main()
{
	printf("\n*************************************************************\n");
	printf("\n********************* DEBUT DES TESTS ***********************\n");
	printf("\n*************************************************************\n");

	int r_printf;
	int r_ft_printf;

	printf("\n*** c ***\n\n\n");
	char ch = 'a';
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%c", ch);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%c", ch);
	ft_printf("' - return = %d\n", r_ft_printf);
	ch = 0;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%c", ch);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ///
	r_ft_printf = ft_printf("%c", ch);
	ft_printf("' - return = %d\n", r_ft_printf);

	printf("\n*** s ***\n\n\n");
	char *str = "salut !";
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%s", str);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%s", str);
	ft_printf("' - return = %d\n", r_ft_printf);
	str = 0;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%s", str);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%s", str);
	ft_printf("' - return = %d\n", r_ft_printf);

	printf("\n*** p ***\n\n\n");
	void *pt = &r_ft_printf;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%p", pt);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%p", pt);
	ft_printf("' - return = %d\n", r_ft_printf);
	pt = 0;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%p", pt);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%p", pt);
	ft_printf("' - return = %d\n", r_ft_printf);

	printf("\n*** d ***\n\n\n");
	int nb;
	nb = 42;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%d", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%d", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = -42;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%d", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%d", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = 0;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%d", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%d", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = 2147483647;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%d", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%d", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = -2147483648;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%d", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%d", nb);
	ft_printf("' - return = %d\n", r_ft_printf);

	printf("\n*** i ***\n\n\n");
	nb = 42;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%i", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%i", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = -42;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%i", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%i", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = 0;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%i", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%i", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = 2147483647;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%i", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%i", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = -2147483648;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%i", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%i", nb);
	ft_printf("' - return = %d\n", r_ft_printf);

	printf("\n*** u ***\n\n\n");
	nb = 42;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%u", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%u", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = -42;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%u", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%u", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = 0;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%u", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%u", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = 4294967295;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%u", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%u", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = -4294967295;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%u", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%u", nb);
	ft_printf("' - return = %d\n", r_ft_printf);

	printf("\n*** x ***\n\n\n");
	nb = 42;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%x", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%x", nb);
	ft_printf("' - return = %d\n\n", r_ft_printf);
	nb = -42;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%x", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%x", nb);
	ft_printf("' - return = %d\n\n", r_ft_printf);
	nb = 0;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%x", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%x", nb);
	ft_printf("' - return = %d\n\n", r_ft_printf);
	nb = 4294967295;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%x", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%x", nb);
	ft_printf("' - return = %d\n\n", r_ft_printf);
	nb = -4294967295;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%x", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%x", nb);
	ft_printf("' - return = %d\n\n", r_ft_printf);

	printf("\n*** X ***\n\n\n");
	nb = 42;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%X", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%X", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = -42;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%X", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%X", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = 0;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%X", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%X", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = 4294967295;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%X", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%X", nb);
	ft_printf("' - return = %d\n", r_ft_printf);
	nb = -4294967295;
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%X", nb);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%X", nb);
	ft_printf("' - return = %d\n", r_ft_printf);

	printf("\n*** %% ***\n\n\n");
	printf("resultat avec printf    : '"); ///
	r_printf = printf("%%");
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("%%");
	ft_printf("' - return = %d\n", r_ft_printf);

	printf("\n*** chaine complete ***\n\n\n");
	printf("resultat avec printf    : '"); ///
	r_printf = printf("resutlat avec printf    :'%c' '%s' '%p' '%d' '%u' '%X' '%%'\n", '!', "hi", &nb, -18, -18, -18);
	printf("' - return = %d\n", r_printf);
	ft_printf("resultat avec ft_printf : '"); ////
	r_ft_printf = ft_printf("resutlat avec printf    :'%c' '%s' '%p' '%d' '%u' '%X' '%%'\n", '!', "hi", &nb, -18, -18, -18);
	ft_printf("' - return = %d\n", r_ft_printf);
}
