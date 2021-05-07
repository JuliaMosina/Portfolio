/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <alanora@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 04:56:42 by student           #+#    #+#             */
/*   Updated: 2020/11/03 23:03:37 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libasm.h"

int b_cleaner(char *buff)
{
	int step;

	if (!buff)
		return (0);
	step = 0;
	while (buff[step])
		buff[step++] = '\0';
	return (step);
}

int	main ()
{
	char buff_c[1000];
	char buff_my[1000];
	char *str_e;
	char *str_s;
	char *str_n;
	char *str_l;
	char *str_ent1;
	char *str_ent2;
	ssize_t read_c;
	ssize_t read_my;
	int fd;

	str_e = "";
	str_ent1 = "\0";
	str_ent2 = "\0";
	str_s = "Test\0";
	str_n = "I really like this project\0";
	str_l = "Nager dans les eaux troubles\nDes lendemains\nAttendre ici la fin\nFlotter dans l'air trop lourd\nDu presque rien\nA qui tendre la main\nSi je dois tomber de haut\nQue ma chute soit lente\nJe n'ai trouvé de repos\nQue dans l'indifference\nPourtant, je voudrais retrouver l'innocence\nMais rien n'a de sens, et rien ne va\nTout est chaos\nA cote\nTous mes ideaux: des mots\nAbimes...\nJe cherche une ame, qui\nPourra m'aider\nJe suis\nD'une generation desenchantee\nDesenchantee\n\0";
	
	printf ("%s\n", "***TESTS ft_strlen***\n");

	printf ("%s\n", "*Test with empty str*");
	printf ("%s\n", "orig:");
	printf ("%lu\n", strlen (str_e));
	printf ("%s\n", "my:");
	printf ("%zu\n", ft_strlen (str_e));

	printf ("%s\n", "*Test with short str*");
	printf ("%s\n", "orig:");
	printf ("%lu\n", strlen (str_s));
	printf ("%s\n", "my:");
	printf ("%zu\n", ft_strlen (str_s));

	printf ("%s\n", "*Test with norm str*");
	printf ("%s\n", "orig:");
	printf ("%lu\n", strlen (str_n));
	printf ("%s\n", "my:");
	printf ("%zu\n", ft_strlen (str_n));

	printf ("%s\n", "*Test with long str*");
	printf ("%s\n", "orig:");
	printf ("%lu\n", strlen (str_l));
	printf ("%s\n", "my:");
	printf ("%zu\n", ft_strlen (str_l));
	printf ("\n");
	
	printf ("%s\n", "***TESTS ft_strcpy***\n");
	
	printf ("%s\n", "*Test with empty str*");
	printf ("%s\n", "orig:");
	printf ("%s\n", strcpy (buff_c, str_e));
	printf ("%s\n", "my:");
	printf ("%s\n", ft_strcpy (buff_my, str_e));

	printf ("%s\n", "*Test with short str*");
	printf ("%s\n", "orig:");
	printf ("%s\n", strcpy (buff_c, str_s));
	printf ("%s\n", "my:");
	printf ("%s\n", ft_strcpy (buff_my, str_s));

	printf ("%s\n", "*Test with norm str*");
	printf ("%s\n", "orig:");
	printf ("%s\n", strcpy (buff_c, str_n));
	printf ("%s\n", "my:");
	printf ("%s\n", ft_strcpy (buff_my, str_n));

	printf ("%s\n", "*Test with long str*");
	printf ("%s\n", "orig:");
	printf ("%s\n", strcpy (buff_c, str_l));
	printf ("%s\n", "my:");
	printf ("%s\n", ft_strcpy (buff_my, str_l));
	
	printf ("buffclean\n");
	printf("%d\n", b_cleaner(buff_c));
	printf("%d\n", b_cleaner(buff_my));
	printf ("\n");

	printf ("%s\n", "***TESTS ft_strcmp***\n");

	printf ("%s\n", "*Test with 2 empty str*");
	printf ("%s\n", "orig:");
	printf ("%d\n", strcmp (str_ent1, str_ent2));
	printf ("%s\n", "my:");
	printf ("%d\n", ft_strcmp (str_ent1, str_ent2));

	printf ("%s\n", "*Test with 1 empty str as 1 arg*");
	printf ("%s\n", "orig:");
	printf ("%d\n", strcmp (str_ent1, str_n));
	printf ("%s\n", "my:");
	printf ("%d\n", ft_strcmp (str_ent1, str_n));

	printf ("%s\n", "*Test with 1 empty str as 2 arg*");
	printf ("%s\n", "orig:");
	printf ("%d\n", strcmp (str_n, str_ent2));
	printf ("%s\n", "my:");
	printf ("%d\n", ft_strcmp (str_n, str_ent2));

	printf ("%s\n", "*Test with diff strs*");
	printf ("%s\n", "orig:");
	printf ("%d\n", strcmp (str_s, str_l));
	printf ("%s\n", "my:");
	printf ("%d\n", ft_strcmp (str_s, str_l));

	printf ("%s\n", "*Test with diff strs vv*");
	printf ("%s\n", "orig:");
	printf ("%d\n", strcmp (str_l, str_s));
	printf ("%s\n", "my:");
	printf ("%d\n", ft_strcmp (str_l, str_s));

	printf ("%s\n", "*Test with equal strs*");
	printf ("%s\n", "orig:");
	printf ("%d\n", strcmp ("Test", "Test"));
	printf ("%s\n", "my:");
	printf ("%d\n", ft_strcmp ("Test", "Test"));

	printf ("%s\n", "*More test with diff strs*");
	printf ("%s\n", "orig:");
	printf ("%d\n", strcmp ("Tests", "Test"));
	printf ("%s\n", "my:");
	printf ("%d\n", ft_strcmp ("Tests", "Test"));

	printf ("%s\n", "*More test with diff strs*");
	printf ("%s\n", "orig:");
	printf ("%d\n", strcmp ("Test", "Tests"));
	printf ("%s\n", "my:");
	printf ("%d\n", ft_strcmp ("Test", "Tests"));
	printf ("\n");

	printf ("%s\n", "***TESTS ft_write***\n");

	printf ("%s\n", "*Test standard*");
	errno = 0;
	printf ("%s\n", "orig:");
	printf ("%zd\n", write (1, "Test correct\n", 13));
	printf("errno: %d\n", errno);
	errno = 0;
	printf ("%s\n", "my:");
	printf ("%zd\n", ft_write (1, "Test correct\n", 13));
	printf("errno: %d\n", errno);

	printf ("%s\n", "*Test wrong fd*");
	errno = 0;
	printf ("%s\n", "orig:");
	printf ("%zd\n", write (-1, "Test correct\n", 13));
	printf("errno: %d\n", errno);
	errno = 0;
	printf ("%s\n", "my:");
	printf ("%zd\n", ft_write (-1, "Test correct\n", 13));
	printf("errno: %d\n", errno);

	printf ("%s\n", "*Test file correct*");
	errno = 0;
	printf ("%s\n", "orig:");
	fd = open ("test_c", O_WRONLY);
	printf ("%zd\n", write (fd, "Test absolutely correct", 23));
	close (fd);
	printf ("errno: %d\n", errno);
	fd = open ("test_c", O_RDONLY);
	read (fd, buff_c, 23);
	close (fd);
	printf ("%s\n", buff_c);
	errno = 0;
	printf ("%s\n", "my:");
	fd = open ("test_my", O_WRONLY);
	printf ("%zd\n", ft_write (fd, "Test absolutely correct", 23));
	close (fd);
	printf ("errno: %d\n", errno);
	fd = open ("test_my", O_RDONLY);
	read (fd, buff_my, 23);
	close (fd);
	printf ("%s\n", buff_my);
	
	printf ("%s\n", "*Test file incorrect*");
	errno = 0;
	printf ("%s\n", "orig:");
	fd = open ("test1_c", O_WRONLY);
	printf ("%zd\n", write (fd, "Test absolutely correct", 23));
	close (fd);
	printf ("errno: %d\n", errno);
	errno = 0;
	printf ("%s\n", "my:");
	fd = open ("test1_my", O_WRONLY);
	printf ("%zd\n", ft_write (fd, "Test absolutely correct", 23));
	close (fd);
	printf ("errno: %d\n", errno);
	printf ("\n");

	printf ("buffclean\n");
	printf("%d\n", b_cleaner(buff_c));
	printf("%d\n", b_cleaner(buff_my));
	printf ("\n");

	printf ("%s\n", "***TESTS ft_read***\n");
	
	printf ("%s\n", "*Read file correct*");
	errno = 0;
	read_c = 0;
	read_my = 0;
	printf ("%s\n", "orig:");
	fd = open ("test_c", O_RDONLY);
	read_c = read (fd, buff_c, 23);
	close (fd);
	printf ("%s\n%zd\nerrno: %d\n", buff_c, read_c, errno);
	errno = 0;
	printf ("%s\n", "my:");
	fd = open ("test_my", O_RDONLY);
	read_my = ft_read (fd, buff_my, 23);
	close (fd);
	printf ("%s\n%zd\nerrno: %d\n", buff_my, read_my, errno);
	errno = 0;

	printf ("buffclean\n");
	printf("%d\n", b_cleaner(buff_c));
	printf("%d\n", b_cleaner(buff_my));
	printf ("\n");

	printf ("%s\n", "*Read file incorrect*");
	errno = 0;
	read_c = 0;
	read_my = 0;
	printf ("%s\n", "orig:");
	fd = open ("test1_c", O_RDONLY);
	read_c = read (fd, buff_c, 23);
	close (fd);
	printf ("%s\n%zd\nerrno: %d\n", buff_c, read_c, errno);
	errno = 0;
	printf ("%s\n", "my:");
	fd = open ("test1_my", O_RDONLY);
	read_my = ft_read (fd, buff_my, 23);
	close (fd);
	printf ("%s\n%zd\nerrno: %d\n", buff_my, read_my, errno);
	errno = 0;

	printf ("%s\n", "*Read from fd 0*");
	errno = 0;
	read_c = 0;
	read_my = 0;
	printf ("%s\n", "orig:");
	read_c = read (0, buff_c, 100);
	printf ("%s\n%zd\nerrno: %d\n", buff_c, read_c, errno);
	errno = 0;
	printf ("%s\n", "my:");
	read_my = ft_read (0, buff_my, 100);
	printf ("%s\n%zd\nerrno: %d\n", buff_my, read_my, errno);

	printf ("buffclean\n");
	printf("%d\n", b_cleaner(buff_c));
	printf("%d\n", b_cleaner(buff_my));
	printf ("\n");

	printf ("%s\n", "*Read with buffer NULL*");
	errno = 0;
	read_c = 0;
	read_my = 0;
	printf ("%s\n", "orig:");
	fd = open ("test_c", O_RDONLY);
	read_c = read (fd, NULL, 100);
	close(fd);
	printf ("%zd\nerrno: %d\n", read_c, errno);
	errno = 0;
	printf ("%s\n", "my:");
	fd = open ("test_my", O_RDONLY);
	read_my = ft_read (fd, NULL, 100);
	close(fd);
	printf ("%zd\nerrno: %d\n", read_my, errno);
	printf ("\n");
	
	printf ("%s\n", "***TESTS ft_strdup***\n");

	printf ("%s\n", "*Empty str*");
	errno = 0;
	printf ("%s\n", "orig:");
	printf ("%s\nerrno: %d\n", strdup (str_e), errno);
	errno = 0;
	printf ("%s\n", "my:");
	printf ("%s\nerrno: %d\n", ft_strdup (str_e), errno);

	printf ("%s\n", "*Short str*");
	errno = 0;
	printf ("%s\n", "orig:");
	printf ("%s\nerrno: %d\n", strdup (str_s), errno);
	errno = 0;
	printf ("%s\n", "my:");
	printf ("%s\nerrno: %d\n", ft_strdup (str_s), errno);

	printf ("%s\n", "*Norm str*");
	errno = 0;
	printf ("%s\n", "orig:");
	printf ("%s\nerrno: %d\n", strdup (str_n), errno);
	errno = 0;
	printf ("%s\n", "my:");
	printf ("%s\nerrno: %d\n", ft_strdup (str_n), errno);

	printf ("%s\n", "*Long str*");
	errno = 0;
	printf ("%s\n", "orig:");
	printf ("%s\nerrno: %d\n", strdup (str_l), errno);
	errno = 0;
	printf ("%s\n", "my:");
	printf ("%s\nerrno: %d\n", ft_strdup (str_l), errno);

	return (0);
}
