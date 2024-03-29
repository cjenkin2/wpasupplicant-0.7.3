/*
 * wpa_supplicant - SME
 * Copyright (c) 2009-2010, Jouni Malinen <j@w1.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#ifndef SME_H
#define SME_H

#ifdef CONFIG_SME

void sme_authenticate(struct wpa_supplicant *wpa_s,
		      struct wpa_bss *bss, struct wpa_ssid *ssid);
void sme_associate(struct wpa_supplicant *wpa_s, enum wpas_mode mode,
		   const u8 *bssid, u16 auth_type);
void sme_event_auth(struct wpa_supplicant *wpa_s, union wpa_event_data *data);
int sme_update_ft_ies(struct wpa_supplicant *wpa_s, const u8 *md,
		      const u8 *ies, size_t ies_len);
void sme_event_assoc_reject(struct wpa_supplicant *wpa_s,
			    union wpa_event_data *data);
void sme_event_auth_timed_out(struct wpa_supplicant *wpa_s,
			      union wpa_event_data *data);
void sme_event_assoc_timed_out(struct wpa_supplicant *wpa_s,
			       union wpa_event_data *data);
void sme_event_disassoc(struct wpa_supplicant *wpa_s,
			union wpa_event_data *data);
void sme_state_changed(struct wpa_supplicant *wpa_s);
void sme_disassoc_while_authenticating(struct wpa_supplicant *wpa_s,
				       const u8 *prev_pending_bssid);
void sme_deinit(struct wpa_supplicant *wpa_s);

#else /* CONFIG_SME */

static inline void sme_authenticate(struct wpa_supplicant *wpa_s,
				    struct wpa_bss *bss,
				    struct wpa_ssid *ssid)
{
}

static inline void sme_event_auth(struct wpa_supplicant *wpa_s,
				  union wpa_event_data *data)
{
}

static inline int sme_update_ft_ies(struct wpa_supplicant *wpa_s, const u8 *md,
				    const u8 *ies, size_t ies_len)
{
	return -1;
}


static inline void sme_event_assoc_reject(struct wpa_supplicant *wpa_s,
					  union wpa_event_data *data)
{
}

static inline void sme_event_auth_timed_out(struct wpa_supplicant *wpa_s,
					    union wpa_event_data *data)
{
}

static inline void sme_event_assoc_timed_out(struct wpa_supplicant *wpa_s,
					     union wpa_event_data *data)
{
}

static inline void sme_event_disassoc(struct wpa_supplicant *wpa_s,
				      union wpa_event_data *data)
{
}

static inline void sme_state_changed(struct wpa_supplicant *wpa_s)
{
}

static inline void
sme_disassoc_while_authenticating(struct wpa_supplicant *wpa_s,
				  const u8 *prev_pending_bssid)
{
}

static inline void sme_deinit(struct wpa_supplicant *wpa_s)
{
}

#endif /* CONFIG_SME */

#endif /* SME_H */
