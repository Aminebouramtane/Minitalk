/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:21:00 by abouramt          #+#    #+#             */
/*   Updated: 2024/05/08 15:59:48 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data g_data;

void handler(int sig)
{
    // printf("%d\n", g_data.counter);
    // printf("%p\n", &g_data.res);
    if (sig == SIGUSR2)
    {
        g_data.res <<= 1;
        g_data.counter++;
        // printf("0\n");
    }
    else if (sig == SIGUSR1)
    {
        g_data.res <<= 1;
        g_data.res |= 1;
        g_data.counter++;
        // printf("1\n");                        
    }
    // printf(">>>>>>>%d\n", g_data.counter);
    // printf("<<<<<<<< %c\n", g_data.res);
    if (g_data.counter == 8)
    {
        // if (g_data.res == '\0')
        // {
        //     kill(info->si_pid, SIGUSR1);
        // }
        write(1, &g_data.res, 1);
        // printf("%p\n", &g_data.res);
        g_data.counter = 0;
        g_data.res = 0;
    }
}

int main()
{
    int     pid;

    g_data.res = 0;
    g_data.counter = 0;
    pid = getpid();
    printf("%d\n", pid);
    // struct sigaction sa;
    // sa.sa_handler = handler;
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while(1);
    // sigaction(SIGUSR1, &sa, NULL);
    // sigaction(SIGUSR2, &sa, NULL);

}

// 0110 0000