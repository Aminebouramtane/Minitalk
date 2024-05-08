/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:36:25 by abouramt          #+#    #+#             */
/*   Updated: 2024/05/08 15:00:15 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void conv_bit(unsigned char my_bit, int pid)
{
    int bit;
    int i = 7;
    while(i >= 0)
    {
       //octet =  0100 0001

       //0000 0000 & 1 = 0
       //        1 &   1 = 1
       // 0000 0010 & 1
        bit = (my_bit >> i) & 1;
        if (bit == 0)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        i--;
        usleep(500);
    }
}

void    send_bit(char *str, int pid)
{
    int     i;

    i = 0;
    while (str[i])
    {
        conv_bit(str[i], pid);
        i++;
    }
}

//unsigned char res = 0;

// 0000 0000
// res  <<= 1 == 0000 0000
// res |= 1; == 0000 0001
// res <<= 1;  0000 0010
// res <<= 1;  0000 0100

// res <<= 1;  0000 1000
// res <<= 1;  0001 0000
// res <<= 1;  0010 0000
// res <<= 1;  0100 0001

//counter++;
int main(int ac, char **av)
{
    // unsigned char a = 'A';
    int     pid;

    // print_bit(a);
    if (ac != 3)
        return (0);
    pid = ft_atoi(av[1]);
    send_bit(av[2], pid);
}