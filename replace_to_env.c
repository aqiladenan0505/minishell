/*
 * Previously printed with the "="
 * export TEMP=1337
 * echo $TEMP, will print "=1337"
 * Now fixed, printing "1337"
*/

void	replace_to_env(char *src, char **dest, t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->envp[i])
	{
		if (ft_strncmp(mini->envp[i], &src[1], ft_strlen(src) - 1) == 0)
		{
			*dest = ft_calloc(ft_strlen(mini->envp[i]) + 1, sizeof(char));
			if (*dest == NULL)
				return (memoryerror(mini));
			ft_strlcpy(*dest, &(mini->envp[i])[ft_strlen(src)],
			ft_strlen(mini->envp[i]) + 1);
			break ;
		}
		i++;
	}
	if (*dest == NULL)
	{
		*dest = ft_calloc(ft_strlen(src) + 1, sizeof(char));
		if (*dest == NULL)
			return (memoryerror(mini));
		ft_strlcpy(*dest, src, ft_strlen(src) + 1);
	}
}
