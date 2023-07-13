/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:49:46 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/13 17:00:01 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// void map_wall_check(t_game game)
// {
//     int x = 0;
//     int y = 0;
//     while (y < game.height)
//     {
//         while (x < game.width)
//         {
//             if (y == 0 || y == game.height - 1)
//             {
//                 if (game.map[y][x] != '1')
//                     ft_error("Map is not closed");
//             }
//             else if (x == 0 || x == game.width - 1)
//             {
//                 if (game.map[y][x] != '1')
//                     ft_error("Map is not closed");
//             }
//             x++;
//         }
//         x = 0;
//         y++;
//     }
// }