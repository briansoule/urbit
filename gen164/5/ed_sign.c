/* gen164/5/ed_sign.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

#include <ed25519.h>

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mcc(Pt5, ed, sign)(
                        u2_noun a,                                //  retain
                        u2_noun b)                                //  retain
  {
    c3_y sig_y[64];
    c3_y sed_y[32];
    c3_y pub_y[64];
    c3_y sec_y[64];

    c3_w mesm_w = u2_cr_met(3, a);
    c3_w mess_w = u2_cr_met(3, b);

    c3_y* mes_y = 0;

    memset(sig_y, 0, 64);
    memset(sed_y, 0, 32);
    memset(pub_y, 0, 64);
    memset(sec_y, 0, 64);

    mes_y = malloc(mesm_w);

    u2_cr_bytes(0, mesm_w, mes_y, a);
    u2_cr_bytes(0, mess_w, sed_y, b);

    ed25519_create_keypair(pub_y, sec_y, sed_y);
    ed25519_sign(sig_y, mes_y, mesm_w, pub_y, sec_y);
    free(mes_y);
    return u2_ci_bytes(64, sig_y);
  }
  u2_weak
  j2_md(Pt5, coed, ed, sign)(
                             u2_noun cor)
  {
    u2_noun a, b;
    if ( u2_no == u2_cr_mean(cor,
                          u2_cv_sam_2, &a, u2_cv_sam_3, &b, 0) ) {
      return u2_cm_bail(c3__fail);
    } else {
      return j2_mcc(Pt5, ed, sign)(a, b);
    }
  }
