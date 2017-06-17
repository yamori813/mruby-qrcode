/*
** mrb_qrcode.c - QRCode class
**
** Copyright (c) Hiroki Mori 2017
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/array.h"
#include "mrb_qrcode.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

int QREncodeData(int level, int version,
    unsigned char *data, int len, unsigned char *buff, int size);

#define MAXBUF (1024*32)

static mrb_value mrb_qrcode_encode(mrb_state *mrb, mrb_value self)
{
  int level, version;
  mrb_value arr;
  mrb_value res;
  int inlen;
  int outlen;
  unsigned char in[MAXBUF];
  unsigned char out[MAXBUF];
  int i, j;

  mrb_get_args(mrb, "iiA", &level, &version, &arr);

  res = mrb_ary_new(mrb);

  inlen = RARRAY_LEN( arr );
  if (inlen > MAXBUF) {
    return res;
  }
  for (i = 0; i < inlen; ++i)
    in[i] = mrb_fixnum( mrb_ary_ref( mrb, arr, i ) );

  outlen = QREncodeData(level, version, in, inlen, out, MAXBUF);
  if(outlen != 0) {
    for (i = 0; i < outlen; ++i)
      mrb_ary_push(mrb, res, mrb_fixnum_value(out[i]));
  }

  return res;
}

void mrb_mruby_qrcode_gem_init(mrb_state *mrb)
{
  struct RClass *qrcode;
  qrcode = mrb_define_class(mrb, "QRCode", mrb->object_class);
  mrb_define_class_method(mrb, qrcode, "encode", mrb_qrcode_encode, MRB_ARGS_REQ(3));
  DONE;
}

void mrb_mruby_qrcode_gem_final(mrb_state *mrb)
{
}

