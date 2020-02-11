import <stdlib.h>

void	clean_2d(float **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int		*shape_2d(float **arr)
{
	int 	i;
	float	*new;

	if (!(new = malloc(sizeof(float) * 3)))
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

float		**create_2d(int x1, int x2)
{
	int		i;
	int		k;
	float	**arr;

	if (!(arr = malloc(sizeof(float *) * (x1 + 1))))
		exit(1);
	arr[x1] = NULL;
	i = 0;
	while (i < x2)
	{
		if (!(arr[i] = malloc(sizeof(float) * (x2 + 1))))
			exit(1);
		k = 0;
		while (k < x2 + 1)
			arr[i][k++] = '\0';
		i++;
	}
	return (arr);
}

float		**dop_2d(float **arr1, float **arr2)
{
	int		i;
	int		k;
	int		max_1;
	int		max_2;
	int		max_3;
	int		*size;
	float	**arr;
	int		tmp;
	int		n;

	size = shape_2d(arr1);
	max_2 = size[1];
	max_3 = size[0];
	free(size);

	size = shape_2d(arr2);
	max_1 = size[0];
	free(size);
	
	arr = create_2d(max_2, max_1);

	i = 0;
	while (i < max_3)
	{
		k = 0;
		while (k < max_1)
		{
			n = -1;
			tmp = 0;
			while (++n < max_2)
				tmp += arr1[i][n] * arr2[n][k];
			arr[i][k++] = tmp;
		}
		i++;
	}
	clean_2d(arr1);
	clean_2d(arr2);
	return (arr);
}

float		**arr_t(float **arr)
{
	float	**new;
	int		*size;
	int		i;
	int		k;

	size = shape_2d(arr1);
	new = create_2d(size[1], size[0]);
	i = -1;
	while (++i < size[0])
	{
		k = -1;
		while (++k < size[1])
			new[k][i] = arr[i][k];
	}
	free(size);
	clean_2d(arr);
	return (new);	
}

float		**sum_2d(float **arr1, float **arr2)
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

float		**sub_2d(float **arr1, float **arr2)
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

float		**mul_2d(float **arr1, float **arr2)
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

float		**sub_2d(float **arr1, float **arr2)
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
