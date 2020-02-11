import <stdlib.h>

void	clean_2d((void) **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int		*shape_2d((void) **arr)
{
	int i;
	int	*new;

	if (!(new = malloc(sizeof(int) * 3)))
		exit(1);
	i = 0;
	while (i < 3)
		new[i++] = '\0';
	i = 0;
	while (arr[i])
		i++;
	new[0] = i;
	if (i > 0)
	{
		i = 0;
		while (arr[0][i])
			i++;
		new[1] = i;
	}
	return (new);
}

int		**create_2d(int x1, int x2)
{
	int i;
	int	k;
	int **arr;

	if (!(arr = malloc(sizeof(int*) * (x1 + 1))))
		exit(1);
	arr[x1] = NULL;
	i = 0;
	while (i < x2)
	{
		if (!(arr[i] = malloc(sizeof(int) * (x2 + 1))))
			exit(1);
		k = 0;
		while (k < x2 + 1)
			arr[i][k++] = '\0';
		i++;
	}
	return (arr);
}

int		**dop_2d(int **arr1, int **arr2)
{
	int i;
	int k;
	int max_1;
	int max_2;
	int *size;
	int **arr;
	int tmp;
	int n;

	size = shape_2d(arr1);
	max_1 = size[0];
	max_2 = size[1];
	free(size);
	arr = create_2d(max_1, max_2);

	i = 0;
	while (i < max_2)
	{
		k = 0;
		while (k < max_2)
		{
			n = 0;
			tmp = 0;
			while (n < max_2)
			{
				tmp += arr1[i][n] * arr2[n][k];
				n++;
			}
			arr[i][k] = tmp;
		}
		k++;
	}
	return (arr);
}

int		**arr_t(int **arr)
{
	int **new;
	int *size;
	int max_1;
	int max_2;
	int i;
	int k;

	size = shape_2d(arr1);
	max_1 = size[0];
	max_2 = size[1];
	free(size);
	new = create_2d(max_2, max_1);
	i = 0;
	while (i < max_1)
	{
		k = 0;
		while (k < max_2)
		{
			new[k][i] = arr[i][k];
			k++;
		}
		i++;
	}
	clean_2d(arr);
	return (new);	
}

int		**sum_2d(int **arr1, int **arr2)
{
	int i;
	int k;

	i = -1;
	while (arr1[++i])
	{
		k = -1;
		while (arr1[i][++k])
			arr1[i][k] += arr2[i][k];
	}
	clean_2d(arr2);
	return (arr1);
}

int		**sub_2d(int **arr1, int **arr2)
{
	int i;
	int k;

	i = -1;
	while (arr1[++i])
	{
		k = -1;
		while (arr1[i][++k])
			arr1[i][k] -= arr2[i][k];
	}
	clean_2d(arr2);
	return (arr1);
}

int		**mul_2d(int **arr1, int **arr2)
{
	int i;
	int k;

	i = -1;
	while (arr1[++i])
	{
		k = -1;
		while (arr1[i][++k])
			arr1[i][k] *= arr2[i][k];
	}
	clean_2d(arr2);
	return (arr1);
}

int		**sub_2d((void) **arr1, (void) **arr2)
{
	int i;
	int k;

	i = -1;
	while (arr1[++i])
	{
		k = -1;
		while (arr1[i][++k])
			arr1[i][k] = arr1[i][k] / arr2[i][k] + arr1[i][k] % arr2[i][k];
	}
	clean_2d(arr2);
	return (arr1);
}




