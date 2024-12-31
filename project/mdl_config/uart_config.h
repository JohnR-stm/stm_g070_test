#ifndef _UART_CONFIG_H_
#define _UART_CONFIG_H_



#define CONF_UART_GPIO_IsEnabledClock           LL_IOP_GRP1_IsEnabledClock
#define CONF_UART_GPIO_EnabledClock             LL_IOP_GRP1_EnableClock

//--- uart1 config ---//
#define CONF_UART1_GPIO_TX_BUS                  LL_IOP_GRP1_PERIPH_GPIOA
#define CONF_UART1_GPIO_RX_BUS                  LL_IOP_GRP1_PERIPH_GPIOA
#define CONF_UART1_GPIO_TX_PORT                 GPIOA 
#define CONF_UART1_GPIO_RX_PORT                 GPIOA
#define CONF_UART1_GPIO_TX_AF                   LL_GPIO_AF_1
#define CONF_UART1_GPIO_RX_AF                   LL_GPIO_AF_1
#define CONF_UART1_GPIO_TX_PIN                  LL_GPIO_PIN_2
#define CONF_UART1_GPIO_RX_PIN                  LL_GPIO_PIN_3




#endif /* _UART_CONFIG_H_ */