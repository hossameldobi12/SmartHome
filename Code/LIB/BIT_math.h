/**
 * @file BIT_math.h
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Var , BitNo)    Var = (Var | (1<<BitNo)) 
#define TOGGLE_BIT(Var , BitNo)    Var = (Var ^ (1<<BitNo))
#define CLEAR_BIT(Var , BitNo)    Var = (Var & ~(1<<BitNo))
#define GET_BIT(Var , BitNo)    (Var>>BitNo & 1)


#endif