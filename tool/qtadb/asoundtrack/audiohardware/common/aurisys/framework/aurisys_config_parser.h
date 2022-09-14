#ifndef MTK_AURISYS_CONFIG_PARSER_H
#define MTK_AURISYS_CONFIG_PARSER_H

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif


/*
 * =============================================================================
 *                     ref struct
 * =============================================================================
 */

struct aurisys_config_t;
struct aurisys_config_dsp_t;
struct aurisys_library_config_t;
struct aurisys_lib_manager_config_t;

/*
 * =============================================================================
 *                     public function
 * =============================================================================
 */

struct aurisys_config_t *parse_aurisys_config(const uint8_t core_type);
void delete_aurisys_config(struct aurisys_config_t *aurisys_config,
                           const uint8_t core_type);

void trans_aurisys_config_hal_to_dsp(
    struct aurisys_config_t *hal,
    struct aurisys_config_dsp_t *dsp);

void init_aurisys_lib_api(
    const struct aurisys_lib_manager_config_t *manager_config,
    struct aurisys_library_config_t *library_config);

void init_aurisys_xml_handler(void);
void deinit_aurisys_xml_handler(void);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* end of MTK_AURISYS_CONFIG_PARSER_H */

