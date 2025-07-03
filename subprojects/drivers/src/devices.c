#include "devices.h"

#include "devices/arctis_pro_wireless.h"
#include "devices/arctis_7_2017.h"
#include "devices/arctis_7_2019.h"
#include "devices/arctis_pro_2019.h"
#include "devices/arctis_pro_gamedac.h"
#include "devices/arctis_9.h"
#include "devices/arctis_1_wireless.h"
#include "devices/arctis_1_xbox.h"
#include "devices/arctis_7x.h"
#include "devices/arctis_7_plus.h"
#include "devices/arctis_7p_plus.h"
#include "devices/arctis_7x_plus.h"
#include "devices/arctis_7_destiny_plus.h"
#include "devices/arctis_nova_7.h"
#include "devices/arctis_nova_7x.h"
#include "devices/arctis_nova_7x_v2.h"
#include "devices/arctis_nova_7p.h"
#include "devices/arctis_nova_7_diablo_iv.h"
#include "devices/arctis_nova_5.h"
#include "devices/arctis_nova_5x.h"

const device_identifier *all_headphone_models[HEADPHONE_COUNT] = {
    &arctis_pro_wireless,
    &arctis_7_2017,
    &arctis_7_2019,
    &arctis_pro_2019,
    &arctis_pro_gamedac,
    &arctis_9,
    &arctis_1_wireless,
    &arctis_1_xbox,
    &arctis_7x,
    &arctis_7_plus,
    &arctis_7p_plus,
    &arctis_7x_plus,
    &arctis_7_destiny_plus,
    &arctis_nova_7,
    &arctis_nova_7x,
    &arctis_nova_7x_v2,
    &arctis_nova_7p,
    &arctis_nova_7_diablo_iv,
    &arctis_nova_5,
    &arctis_nova_5x};

const size_t all_headphone_models_count = HEADPHONE_COUNT;
