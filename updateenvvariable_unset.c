/*
 * Refactored function
 * Previously faced segfault issues when unsetting env on my end
*/
void	updateenvvariable_unset(t_mini *mini, char **strs)
{
	int		i;
	int		j;
	int		flag;
	char	**splits;

	i = 0;
	j = 0;
	flag = 0;
	while (i < mini->envplen)
	{
		j = 0;
		splits = ft_split(mini->envp[i], '=');
		if (ft_strncmp(splits[0], strs[1], ft_strlen(strs[1])) == 0
			&& ft_strlen(strs[1]) == ft_strlen(splits[0]))
			flag = 1;
		while (splits[j] != NULL)
		{
			free(splits[j]);
			j++;
		}
		free(splits);
		if (flag == 1)
		{
			updateenvvariable_unset2(mini, &i);
			break ;
		}
		i++;
	}
}
