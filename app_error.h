/* Copyright (c) 2013 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */
 
/** @file
 *
 * @defgroup app_error Common application error handler
 * @{
 * @ingroup app_common
 *
 * @brief Common application error handler and macros for utilizing a common error handler.
 */
/** @文件
? *
? * @defgroup app_error常见的应用程序错误处理程序
? * @ {
? * @ingroup app_common
? *
? * @brief通用应用程序错误处理程序和用于利用通用错误处理程序的宏。
? */

#ifndef APP_ERROR_H__
#define APP_ERROR_H__

#include <stdint.h>
#include <stdbool.h>
#include "nrf_error.h"

/**@brief Function for error handling, which is called when an error has occurred. 
 *
 * @param[in] error_code  Error code supplied to the handler.
 * @param[in] line_num    Line number where the handler is called.
 * @param[in] p_file_name Pointer to the file name. 
 */
 /** @ brief用于错误处理的函数，在发生错误时调用。
? *
? * @param [in] error_code提供给处理程序的错误代码。
? * @param [in] line_num调用处理程序的行号。
? * @param [in] p_file_name指向文件名的指针。
? */
void app_error_handler(uint32_t error_code, uint32_t line_num, const uint8_t * p_file_name);

/**@brief Macro for calling error handler function. 
 *
 * @param[in] ERR_CODE Error code supplied to the error handler.
 */
#ifdef DEBUG
#define APP_ERROR_HANDLER(ERR_CODE)                         \
    do                                                      \
    {                                                       \
        app_error_handler((ERR_CODE), __LINE__, (uint8_t*) __FILE__);  \
    } while (0)
#else
		
#define APP_ERROR_HANDLER(ERR_CODE)                         \
    do                                                      \
    {                                                       \
        app_error_handler((ERR_CODE), 0, 0);  \
    } while (0)
#endif
/**@brief Macro for calling error handler function if supplied error code any other than NRF_SUCCESS. 
 *
 * @param[in] ERR_CODE Error code supplied to the error handler.
 */    
/** @ brief宏，如果提供的错误代码不是NRF_SUCCESS，则用于调用错误处理函数。
? *
? * @param [in] ERR_CODE提供给错误处理程序的错误代码。
? */
		
#define APP_ERROR_CHECK(ERR_CODE)                           \
    do                                                      \
    {                                                       \
        const uint32_t LOCAL_ERR_CODE = (ERR_CODE);         \
        if (LOCAL_ERR_CODE != NRF_SUCCESS)                  \
        {                                                   \
            APP_ERROR_HANDLER(LOCAL_ERR_CODE);              \
        }                                                   \
    } while (0)    
    
/**@brief Macro for calling error handler function if supplied boolean value is false. 
 *
 * @param[in] BOOLEAN_VALUE Boolean value to be evaluated.
 */
/** @ brief如果提供的布尔值为false，则用于调用错误处理程序函数的宏。
? *
? * @param [in] BOOLEAN_VALUE要评估的布尔值。
? */
#define APP_ERROR_CHECK_BOOL(BOOLEAN_VALUE)                   \
    do                                                        \
    {                                                         \
        const uint32_t LOCAL_BOOLEAN_VALUE = (BOOLEAN_VALUE); \
        if (!LOCAL_BOOLEAN_VALUE)                             \
        {                                                     \
            APP_ERROR_HANDLER(0);                             \
        }                                                     \
    } while (0)        

#endif // APP_ERROR_H__

/** @} */
