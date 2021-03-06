//
//  riscv-pte.h
//

#ifndef riscv_pte_h
#define riscv_pte_h

namespace riscv {

	enum {
		pte_flag_V     = 1<<0, /* Valid */
		pte_flag_R     = 1<<1, /* Read */
		pte_flag_W     = 1<<2, /* Write */
		pte_flag_X     = 1<<3, /* Execute */
		pte_flag_U     = 1<<4, /* User */
		pte_flag_G     = 1<<5, /* Global */
		pte_flag_A     = 1<<6, /* Accessed */
		pte_flag_D     = 1<<7, /* Dirty */
		pte_flag_RSRV1 = 1<<8, /* Reserved for SW 1 */
		pte_flag_RSRV2 = 1<<9, /* Reserved for SW 2 */
	};

	/* sv32 */

	union sv32_va {
		struct { u32 val; } xu;
		struct {
			u32 pg_off : 12;
			u32 vpn    : 10; /* 10,10 */
		} va;
	};

	union sv32_pa {
		struct { u64 val; } lu;
		struct {
			u64 pg_off  : 12;
			u64 ppn     : 22; /* 12,10 */
			u64 rsrv_30 : 30;
		} pa;
	};

	union sv32_pte {
		struct { u32 val; } xu;
		struct {
			u32 flags   : 10;
			u32 ppn     : 22; /* 12,10 */
		} val;
	};

	struct sv32 {
		enum {
			levels = 2,
			bits = 10,
			size = sizeof(sv32_pte) >> 3,
		};
		typedef sv32_va  va_type;
		typedef sv32_pa  pa_type;
		typedef sv32_pte pte_type;
	};

	/* sv39 */

	union sv39_va {
		struct { u64 val; } lu;
		struct {
			u64 pg_off  : 12;
			u64 vpn_0   : 27; /* 9,9,9 */
			u64 rsrv_25 : 25;
		} va;
	};

	union sv39_pa {
		struct { u64 val; } lu;
		struct {
			u64 pg_off  : 12;
			u64 ppn     : 38; /* 20,9,9 */
			u64 rsrv_14 : 14;
		} pa;
	};

	union sv39_pte {
		struct { u64 val; } lu;
		struct {
			u64 flags   : 10;
			u64 ppn     : 38; /* 20,9,9 */
			u64 rsrv_16 : 16;
		} val;
	};

	struct sv39 {
		enum {
			levels = 3,
			bits = 9,
			size = sizeof(sv39_pte) >> 3,
		};
		typedef sv39_va  va_type;
		typedef sv39_pa  pa_type;
		typedef sv39_pte pte_type;
	};

	/* sv48 */

	union sv48_va {
		struct { u64 val; } lu;
		struct {
			u64 pg_off  : 12;
			u64 vpn     : 36; /* 9,9,9,9 */
			u64 rsrv_16 : 16;
		} va;
	};

	union sv48_pa {
		struct { u64 val; } lu;
		struct {
			u64 pg_off  : 12;
			u64 ppn     : 38; /* 11,9,9,9 */
			u64 rsrv_14 : 14;
		} pa;
	};

	union sv48_pte {
		struct { u64 val; } lu;
		struct {
			u64 flags   : 10;
			u64 ppn     : 38; /* 11,9,9,9 */
			u64 rsrv_16 : 16;
		} val;
	};

	struct sv48 {
		enum {
			levels = 4,
			bits = 9,
			size = sizeof(sv48_pte) >> 3,
		};
		typedef sv48_va  va_type;
		typedef sv48_pa  pa_type;
		typedef sv48_pte pte_type;
	};

}

#endif
