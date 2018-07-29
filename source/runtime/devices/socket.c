#include <switch.h>
#include <netinet/in.h>

static const SocketInitConfig g_defaultSocketInitConfig = {
    .bsdsockets_version = 1,
    
    .tcp_tx_buf_size        = 0x8000,
    .tcp_rx_buf_size        = 0x10000,
    .tcp_tx_buf_max_size    = 0x40000,
    .tcp_rx_buf_max_size    = 0x40000,
    
    .udp_tx_buf_size = 0x2400,
    .udp_rx_buf_size = 0xA500,
    
    .sb_efficiency = 4,
    
    .serialized_out_addrinfos_max_size  = 0x1000,
    .serialized_out_hostent_max_size    = 0x200,
    .bypass_nsd                         = false,
    .dns_timeout                        = 0,
};

const SocketInitConfig *socketGetDefaultInitConfig(void) {
    return &g_defaultSocketInitConfig;
}

Result socketInitialize(const SocketInitConfig *config) {
    return 0;
}

void socketExit(void) {
    
}
