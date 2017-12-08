#pragma once
#include "Boundary.h"
#include "ProblemSpace.h"
#include "Field.h"

class PMLmedia
{
private:
	Boundary b;
	Cell c;
	ProblemSpace ps;
	EMobject EM;
	double *sigma_pex_xn, *sigma_pmx_xn, *kappa_ex_xn, *kappa_mx_xn, *alpha_ex_xn, *alpha_mx_xn, *cpml_b_ex_xn, *cpml_a_ex_xn, *cpml_b_mx_xn, *cpml_a_mx_xn;
	double ***Psi_eyx_xn, ***Psi_ezx_xn, ***Psi_hyx_xn, ***Psi_hzx_xn;
	double ***CPsi_eyx_xn, ***CPsi_ezx_xn, ***CPsi_hyx_xn, ***CPsi_hzx_xn;
	double *sigma_pex_xp, *sigma_pmx_xp, *kappa_ex_xp, *kappa_mx_xp, *alpha_ex_xp, *alpha_mx_xp, *cpml_b_ex_xp, *cpml_a_ex_xp, *cpml_b_mx_xp, *cpml_a_mx_xp;
	double ***Psi_eyx_xp, ***Psi_ezx_xp, ***Psi_hyx_xp, ***Psi_hzx_xp;
	double ***CPsi_eyx_xp, ***CPsi_ezx_xp, ***CPsi_hyx_xp, ***CPsi_hzx_xp;
	double *sigma_pey_yn, *sigma_pmy_yn, *kappa_ey_yn, *kappa_my_yn, *alpha_ey_yn, *alpha_my_yn, *cpml_b_ey_yn, *cpml_a_ey_yn, *cpml_b_my_yn, *cpml_a_my_yn;
	double ***Psi_ezy_yn, ***Psi_exy_yn, ***Psi_hzy_yn, ***Psi_hxy_yn;
	double ***CPsi_ezy_yn, ***CPsi_exy_yn, ***CPsi_hzy_yn, ***CPsi_hxy_yn;
	double *sigma_pey_yp, *sigma_pmy_yp, *kappa_ey_yp, *kappa_my_yp, *alpha_ey_yp, *alpha_my_yp, *cpml_b_ey_yp, *cpml_a_ey_yp, *cpml_b_my_yp, *cpml_a_my_yp;
	double ***Psi_exy_yp, ***Psi_ezy_yp, ***Psi_hxy_yp, ***Psi_hzy_yp;
	double ***CPsi_ezy_yp, ***CPsi_exy_yp, ***CPsi_hzy_yp, ***CPsi_hxy_yp;
	double *sigma_pez_zn, *sigma_pmz_zn, *kappa_ez_zn, *kappa_mz_zn, *alpha_ez_zn, *alpha_mz_zn, *cpml_b_ez_zn, *cpml_a_ez_zn, *cpml_b_mz_zn, *cpml_a_mz_zn;
	double ***Psi_eyz_zn, ***Psi_exz_zn, ***Psi_hyz_zn, ***Psi_hxz_zn;
	double ***CPsi_eyz_zn, ***CPsi_exz_zn, ***CPsi_hyz_zn, ***CPsi_hxz_zn;
	double *sigma_pez_zp, *sigma_pmz_zp, *kappa_ez_zp, *kappa_mz_zp, *alpha_ez_zp, *alpha_mz_zp, *cpml_b_ez_zp, *cpml_a_ez_zp, *cpml_b_mz_zp, *cpml_a_mz_zp;
	double ***Psi_exz_zp, ***Psi_eyz_zp, ***Psi_hxz_zp, ***Psi_hyz_zp;
	double ***CPsi_eyz_zp, ***CPsi_exz_zp, ***CPsi_hyz_zp, ***CPsi_hxz_zp;
public:
	PMLmedia();
	PMLmedia(ProblemSpace ps, Boundary b, Cell c);
	~PMLmedia();
	void saveAllArrayXn();
	void saveAllArrayXp();
	void saveAllArrayYn();
	void saveAllArrayYp();
	void saveAllArrayZn();
	void saveAllArrayZp();
	void initCPMLboundaryXn();
	void initCPMLboundaryXp();
	void initCPMLboundaryYn();
	void initCPMLboundaryYp();
	void initCPMLboundaryZn();
	void initCPMLboundaryZp();
	void initAllCPMLboundary();
	void applyCPML2Hfield();
	void applyCPML2Efield();
};

