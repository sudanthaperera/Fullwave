#include "PMLmedia.h"


PMLmedia::PMLmedia()
{
}


PMLmedia::~PMLmedia()
{
}

void PMLmedia::saveAllArrayXn(){
	save1DArray<double>(sigma_pex_xn, "sigma_pex_xn");
	save1DArray<double>(sigma_pmx_xn, "sigma_pmx_xn");
	save1DArray<double>(kappa_ex_xn, "kappa_ex_xn");
	save1DArray<double>(kappa_mx_xn, "kappa_mx_xn");
	save1DArray<double>(alpha_ex_xn, "alpha_ex_xn");
	save1DArray<double>(alpha_mx_xn, "alpha_mx_xn");
	save1DArray<double>(cpml_b_ex_xn, "cpml_b_ex_xn");
	save1DArray<double>(cpml_a_ex_xn, "cpml_a_ex_xn");
	save1DArray<double>(cpml_b_mx_xn, "cpml_b_mx_xn");
	save1DArray<double>(cpml_a_mx_xn, "cpml_a_mx_xn");
	save3DArray<double>(Psi_eyx_xn, "Psi_eyx_xn");
	save3DArray<double>(Psi_ezx_xn, "Psi_ezx_xn");
	save3DArray<double>(Psi_hyx_xn, "Psi_hyx_xn");
	save3DArray<double>(Psi_hzx_xn, "Psi_hzx_xn");
	save3DArray<double>(CPsi_eyx_xn, "CPsi_eyx_xn");
	save3DArray<double>(CPsi_ezx_xn, "CPsi_ezx_xn");
	save3DArray<double>(CPsi_hyx_xn, "CPsi_hyx_xn");
	save3DArray<double>(CPsi_hzx_xn, "CPsi_hzx_xn");
}

void PMLmedia::saveAllArrayXp(){
	save1DArray<double>(sigma_pex_xp, "sigma_pex_xp");
	save1DArray<double>(sigma_pmx_xp, "sigma_pmx_xp");
	save1DArray<double>(kappa_ex_xp, "kappa_ex_xp");
	save1DArray<double>(kappa_mx_xp, "kappa_mx_xp");
	save1DArray<double>(alpha_ex_xp, "alpha_ex_xp");
	save1DArray<double>(alpha_mx_xp, "alpha_mx_xp");
	save1DArray<double>(cpml_b_ex_xp, "cpml_b_ex_xp");
	save1DArray<double>(cpml_a_ex_xp, "cpml_a_ex_xp");
	save1DArray<double>(cpml_b_mx_xp, "cpml_b_mx_xp");
	save1DArray<double>(cpml_a_mx_xp, "cpml_a_mx_xp");
	save3DArray<double>(Psi_eyx_xp, "Psi_eyx_xp");
	save3DArray<double>(Psi_ezx_xp, "Psi_ezx_xp");
	save3DArray<double>(Psi_hyx_xp, "Psi_hyx_xp");
	save3DArray<double>(Psi_hzx_xp, "Psi_hzx_xp");
	save3DArray<double>(CPsi_eyx_xp, "CPsi_eyx_xp");
	save3DArray<double>(CPsi_ezx_xp, "CPsi_ezx_xp");
	save3DArray<double>(CPsi_hyx_xp, "CPsi_hyx_xp");
	save3DArray<double>(CPsi_hzx_xp, "CPsi_hzx_xp");
}

void PMLmedia::saveAllArrayYn(){
	save1DArray<double>(sigma_pey_yn, "sigma_pey_yn");
	save1DArray<double>(sigma_pmy_yn, "sigma_pmy_yn");
	save1DArray<double>(kappa_ey_yn, "kappa_ey_yn");
	save1DArray<double>(kappa_my_yn, "kappa_my_yn");
	save1DArray<double>(alpha_ey_yn, "alpha_ey_yn");
	save1DArray<double>(alpha_my_yn, "alpha_my_yn");
	save1DArray<double>(cpml_b_ey_yn, "cpml_b_ey_yn");
	save1DArray<double>(cpml_a_ey_yn, "cpml_a_ey_yn");
	save1DArray<double>(cpml_b_my_yn, "cpml_b_my_yn");
	save1DArray<double>(cpml_a_my_yn, "cpml_a_my_yn");
	save3DArray<double>(Psi_exy_yn, "Psi_exy_yn");
	save3DArray<double>(Psi_ezy_yn, "Psi_ezy_yn");
	save3DArray<double>(Psi_hxy_yn, "Psi_hxy_yn");
	save3DArray<double>(Psi_hzy_yn, "Psi_hzy_yn");
	save3DArray<double>(CPsi_hxy_yn, "CPsi_hxy_yn");
	save3DArray<double>(CPsi_ezy_yn, "CPsi_ezy_yn");
	save3DArray<double>(CPsi_exy_yn, "CPsi_exy_yn");
	save3DArray<double>(CPsi_hzy_yn, "CPsi_hzy_yn");
}

void PMLmedia::saveAllArrayYp(){
	save1DArray<double>(sigma_pey_yp, "sigma_pey_yp");
	save1DArray<double>(sigma_pmy_yp, "sigma_pmy_yp");
	save1DArray<double>(kappa_ey_yp, "kappa_ey_yp");
	save1DArray<double>(kappa_my_yp, "kappa_my_yp");
	save1DArray<double>(alpha_ey_yp, "alpha_ey_yp");
	save1DArray<double>(alpha_my_yp, "alpha_my_yp");
	save1DArray<double>(cpml_b_ey_yp, "cpml_b_ey_yp");
	save1DArray<double>(cpml_a_ey_yp, "cpml_a_ey_yp");
	save1DArray<double>(cpml_b_my_yp, "cpml_b_my_yp");
	save1DArray<double>(cpml_a_my_yp, "cpml_a_my_yp");
	save3DArray<double>(Psi_exy_yp, "Psi_exy_yp");
	save3DArray<double>(Psi_ezy_yp, "Psi_ezy_yp");
	save3DArray<double>(Psi_hxy_yp, "Psi_hxy_yp");
	save3DArray<double>(Psi_hzy_yp, "Psi_hzy_yp");
	save3DArray<double>(CPsi_ezy_yp, "CPsi_ezy_yp");
	save3DArray<double>(CPsi_exy_yp, "CPsi_exy_yp");
	save3DArray<double>(CPsi_hzy_yp, "CPsi_hzy_yp");
	save3DArray<double>(CPsi_hxy_yp, "CPsi_hxy_yp");
}

void PMLmedia::saveAllArrayZn(){
	save1DArray<double>(sigma_pez_zn, "sigma_pez_zn");
	save1DArray<double>(sigma_pmz_zn, "sigma_pmz_zn");
	save1DArray<double>(kappa_ez_zn, "kappa_ez_zn");
	save1DArray<double>(kappa_mz_zn, "kappa_mz_zn");
	save1DArray<double>(alpha_ez_zn, "alpha_ez_zn");
	save1DArray<double>(alpha_mz_zn, "alpha_mz_zn");
	save1DArray<double>(cpml_b_ez_zn, "cpml_b_ez_zn");
	save1DArray<double>(cpml_a_ez_zn, "cpml_a_ez_zn");
	save1DArray<double>(cpml_b_mz_zn, "cpml_b_mz_zn");
	save1DArray<double>(cpml_a_mz_zn, "cpml_a_mz_zn");
	save3DArray<double>(Psi_eyz_zn, "Psi_eyz_zn");
	save3DArray<double>(Psi_exz_zn, "Psi_exz_zn");
	save3DArray<double>(Psi_hyz_zn, "Psi_hyz_zn");
	save3DArray<double>(Psi_hxz_zn, "Psi_hxz_zn");
	save3DArray<double>(CPsi_eyz_zn, "CPsi_eyz_zn");
	save3DArray<double>(CPsi_exz_zn, "CPsi_exz_zn");
	save3DArray<double>(CPsi_hyz_zn, "CPsi_hyz_zn");
	save3DArray<double>(CPsi_hxz_zn, "CPsi_hxz_zn");
}

void PMLmedia::saveAllArrayZp(){
	save1DArray<double>(sigma_pez_zp, "sigma_pez_zp");
	save1DArray<double>(sigma_pmz_zp, "sigma_pmz_zp");
	save1DArray<double>(kappa_ez_zp, "kappa_ez_zp");
	save1DArray<double>(kappa_mz_zp, "kappa_mz_zp");
	save1DArray<double>(alpha_ez_zp, "alpha_ez_zp");
	save1DArray<double>(alpha_mz_zp, "alpha_mz_zp");
	save1DArray<double>(cpml_b_ez_zp, "cpml_b_ez_zp");
	save1DArray<double>(cpml_a_ez_zp, "cpml_a_ez_zp");
	save1DArray<double>(cpml_b_mz_zp, "cpml_b_mz_zp");
	save1DArray<double>(cpml_a_mz_zp, "cpml_a_mz_zp");
	save3DArray<double>(Psi_exz_zp, "Psi_exz_zp");
	save3DArray<double>(Psi_eyz_zp, "Psi_eyz_zp");
	save3DArray<double>(Psi_hxz_zp, "Psi_hxz_zp");
	save3DArray<double>(Psi_hyz_zp, "Psi_hyz_zp");
	save3DArray<double>(CPsi_eyz_zp, "CPsi_eyz_zp");
	save3DArray<double>(CPsi_exz_zp, "CPsi_exz_zp");
	save3DArray<double>(CPsi_hyz_zp, "CPsi_hyz_zp");
	save3DArray<double>(CPsi_hxz_zp, "CPsi_hxz_zp");
}

PMLmedia::PMLmedia(ProblemSpace ps, Boundary b, Cell c){
	this->ps = ps;
	this->b = b;
	this->c = c;
	this->EM = *(new EMobject());
}

void PMLmedia::initCPMLboundaryXn(){
	//Initialize cpml for xn region
	if (b.getCPMLxn()){
		int order = b.getOrder(); //order of the polynomial distribution
		double sigmaFactor = b.getSigmaFactor();
		double kappaMax = b.getKappaMax();
		double alphaMin = b.getAlphaMax();
		double alphaMax = b.getAlphaMax();
		double sigmaMax;
		int ncells;
		double *rho_e_xn, *rho_m_xn;

		//define one-dimensional temporary cpml parameter arrays 
		sigmaMax = sigmaFactor*(order + 1) / (150 * PI*c.getDeltaX());
		ncells = b.getCellCountXn();
		
		rho_e_xn = gen1DArray<double>(ncells, 0.0);
		rho_m_xn = gen1DArray<double>(ncells, 0.0);
		sigma_pex_xn = gen1DArray<double>(ncells, 0.0);
		sigma_pmx_xn = gen1DArray<double>(ncells, 0.0);
		kappa_ex_xn = gen1DArray<double>(ncells, 0.0);
		kappa_mx_xn = gen1DArray<double>(ncells, 0.0);
		alpha_ex_xn = gen1DArray<double>(ncells, 0.0);
		alpha_mx_xn = gen1DArray<double>(ncells, 0.0);
		cpml_b_ex_xn = gen1DArray<double>(ncells, 0.0);
		cpml_a_ex_xn = gen1DArray<double>(ncells, 0.0);
		cpml_b_mx_xn = gen1DArray<double>(ncells, 0.0);
		cpml_a_mx_xn = gen1DArray<double>(ncells, 0.0);

		for (int ncells_ind = 0; ncells_ind < ncells; ncells_ind++){
			//sigma_pex_xn[ncells_ind] = 0.0;
			sigma_pmx_xn[ncells_ind] = 0.0;

			kappa_ex_xn[ncells_ind] = 0.0;
			kappa_mx_xn[ncells_ind] = 0.0;

			alpha_ex_xn[ncells_ind] = 0.0;
			alpha_mx_xn[ncells_ind] = 0.0;

			cpml_b_ex_xn[ncells_ind] = 0.0;
			cpml_a_ex_xn[ncells_ind] = 0.0;
			cpml_b_mx_xn[ncells_ind] = 0.0;
			cpml_a_mx_xn[ncells_ind] = 0.0;

			rho_e_xn[ncells_ind] = (((double)ncells - (double)ncells_ind) - 0.75) / ((double)ncells);
			rho_m_xn[ncells_ind] = (((double)ncells - (double)ncells_ind) - 0.25) / ((double)ncells);

			sigma_pex_xn[ncells_ind] = 1;
			sigma_pmx_xn[ncells_ind] = 1;

			for (int p_order_ind = 1; p_order_ind <= order; p_order_ind++){
				sigma_pex_xn[ncells_ind] = sigma_pex_xn[ncells_ind] * rho_e_xn[ncells_ind];
				sigma_pmx_xn[ncells_ind] = sigma_pmx_xn[ncells_ind] * rho_m_xn[ncells_ind];
			}

			kappa_ex_xn[ncells_ind] = sigma_pex_xn[ncells_ind];
			kappa_mx_xn[ncells_ind] = sigma_pmx_xn[ncells_ind];

			sigma_pex_xn[ncells_ind] = sigmaMax*sigma_pex_xn[ncells_ind];
			sigma_pmx_xn[ncells_ind] = sigmaMax*sigma_pmx_xn[ncells_ind];

			kappa_ex_xn[ncells_ind] = 1 + (kappaMax - 1)*kappa_ex_xn[ncells_ind];
			kappa_mx_xn[ncells_ind] = 1 + (kappaMax - 1)*kappa_mx_xn[ncells_ind];

			sigma_pmx_xn[ncells_ind] = (MU0 / EPS0)*sigma_pmx_xn[ncells_ind];
			alpha_ex_xn[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_e_xn[ncells_ind]);
			alpha_mx_xn[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_m_xn[ncells_ind]);
			alpha_mx_xn[ncells_ind] = (MU0 / EPS0)*alpha_mx_xn[ncells_ind];

			//define one-dimensional cpml parameter arrays 
			cpml_b_ex_xn[ncells_ind] = exp((-c.getDeltaT() / EPS0)*((sigma_pex_xn[ncells_ind] / kappa_ex_xn[ncells_ind]) + alpha_ex_xn[ncells_ind]));
			cpml_a_ex_xn[ncells_ind] = (1 / c.getDeltaX())*(cpml_b_ex_xn[ncells_ind] - 1.0)* sigma_pex_xn[ncells_ind] / (kappa_ex_xn[ncells_ind] * (sigma_pex_xn[ncells_ind] + kappa_ex_xn[ncells_ind] * alpha_ex_xn[ncells_ind]));
			cpml_b_mx_xn[ncells_ind] = exp((-c.getDeltaT() / MU0)*((sigma_pmx_xn[ncells_ind] / kappa_mx_xn[ncells_ind]) + alpha_mx_xn[ncells_ind]));
			cpml_a_mx_xn[ncells_ind] = (1 / c.getDeltaX())*(cpml_b_mx_xn[ncells_ind] - 1.0)*sigma_pmx_xn[ncells_ind] / (kappa_mx_xn[ncells_ind] * (sigma_pmx_xn[ncells_ind] + kappa_mx_xn[ncells_ind] * alpha_mx_xn[ncells_ind]));
		}

		//Create and initialize 2D cpml convolution parameters 
		Psi_eyx_xn = gen3DArray<double>(ncells, ps.getNY(), ps.getNZ() + 1, 0.0);
		Psi_ezx_xn = gen3DArray<double>(ncells, ps.getNY() + 1, ps.getNZ(), 0.0);
		Psi_hyx_xn = gen3DArray<double>(ncells, ps.getNY() + 1, ps.getNZ(), 0.0);
		Psi_hzx_xn = gen3DArray<double>(ncells, ps.getNY(), ps.getNZ() + 1, 0.0);

		//Create and initialize 2D cpml convolution coefficients

		CPsi_eyx_xn = gen3DArray<double>(ncells, ps.getNY(), ps.getNZ() + 1, 0.0);
		CPsi_hzx_xn = gen3DArray<double>(ncells, ps.getNY(), ps.getNZ() + 1, 0.0);
		CPsi_ezx_xn = gen3DArray<double>(ncells, ps.getNY() + 1, ps.getNZ(), 0.0);
		CPsi_hyx_xn = gen3DArray<double>(ncells, ps.getNY() + 1, ps.getNZ(), 0.0);

		for (int i = 0; i<ncells; i++){
			for (int j = 0; j<ps.getNY() + 1; j++){
				for (int k = 0; k<ps.getNZ() + 1; k++){
					if (j<ps.getNY()){
						CPsi_eyx_xn[i][j][k] = EM.getCeyhz(i + 1, j, k)*c.getDeltaX();
						EM.setCeyhz(i + 1, j, k, EM.getCeyhz(i + 1, j, k) / kappa_ex_xn[i]);
						CPsi_hzx_xn[i][j][k] = EM.getChzey(i, j, k)*c.getDeltaX();
						EM.setChzey(i, j, k, EM.getChzey(i, j, k) / kappa_mx_xn[i]);
					}
					if (k<ps.getNZ()){
						CPsi_ezx_xn[i][j][k] = EM.getCezhy(i + 1, j, k)*c.getDeltaX();
						EM.setCezhy(i + 1, j, k, EM.getCezhy(i + 1, j, k) / kappa_ex_xn[i]);
						CPsi_hyx_xn[i][j][k] = EM.getChyez(i, j, k)*c.getDeltaX();
						EM.setChyez(i, j, k, EM.getChyez(i, j, k) / kappa_mx_xn[i]);
					}
				}
			}
		}
	}
}

void PMLmedia::initCPMLboundaryXp(){
	//Initialize cpml for xp region
	if (b.getCPMLxp()){
		int order = b.getOrder(); //order of the polynomial distribution
		double sigmaFactor = b.getSigmaFactor();
		double kappaMax = b.getKappaMax();
		double alphaMin = b.getAlphaMax();
		double alphaMax = b.getAlphaMax();
		double sigmaMax;
		int ncells;
		double *rho_e_xp, *rho_m_xp;

		//define one-dimensional temporary cpml parameter arrays 
		sigmaMax = sigmaFactor*(order + 1) / (150 * PI*c.getDeltaX());
		ncells = b.getCellCountXp();

		rho_e_xp = gen1DArray<double>(ncells, 0.0);
		rho_m_xp = gen1DArray<double>(ncells, 0.0);
		sigma_pex_xp = gen1DArray<double>(ncells, 0.0);
		sigma_pmx_xp = gen1DArray<double>(ncells, 0.0);
		kappa_ex_xp = gen1DArray<double>(ncells, 0.0);
		kappa_mx_xp = gen1DArray<double>(ncells, 0.0);
		alpha_ex_xp = gen1DArray<double>(ncells, 0.0);
		alpha_mx_xp = gen1DArray<double>(ncells, 0.0);
		cpml_b_ex_xp = gen1DArray<double>(ncells, 0.0);
		cpml_a_ex_xp = gen1DArray<double>(ncells, 0.0);
		cpml_b_mx_xp = gen1DArray<double>(ncells, 0.0);
		cpml_a_mx_xp = gen1DArray<double>(ncells, 0.0);

		for (int ncells_ind = 0; ncells_ind<ncells; ncells_ind++){
			rho_e_xp[ncells_ind] = (((double)ncells_ind + 1) - 0.75) / ((double)ncells);
			rho_m_xp[ncells_ind] = (((double)ncells_ind + 1) - 0.25) / ((double)ncells);

			sigma_pex_xp[ncells_ind] = 1;
			sigma_pmx_xp[ncells_ind] = 1;

			int p_order_ind;
			for (p_order_ind = 1; p_order_ind <= order; p_order_ind++){
				sigma_pex_xp[ncells_ind] = sigma_pex_xp[ncells_ind] * rho_e_xp[ncells_ind];
				sigma_pmx_xp[ncells_ind] = sigma_pmx_xp[ncells_ind] * rho_m_xp[ncells_ind];
			}

			kappa_ex_xp[ncells_ind] = sigma_pex_xp[ncells_ind];
			kappa_mx_xp[ncells_ind] = sigma_pmx_xp[ncells_ind];

			sigma_pex_xp[ncells_ind] = sigmaMax*sigma_pex_xp[ncells_ind];
			sigma_pmx_xp[ncells_ind] = sigmaMax*sigma_pmx_xp[ncells_ind];

			kappa_ex_xp[ncells_ind] = 1 + (kappaMax - 1)*kappa_ex_xp[ncells_ind];
			kappa_mx_xp[ncells_ind] = 1 + (kappaMax - 1)*kappa_mx_xp[ncells_ind];

			sigma_pmx_xp[ncells_ind] = (MU0 / EPS0)*sigma_pmx_xp[ncells_ind];
			alpha_ex_xp[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_e_xp[ncells_ind]);
			alpha_mx_xp[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_m_xp[ncells_ind]);
			alpha_mx_xp[ncells_ind] = (MU0 / EPS0)*alpha_mx_xp[ncells_ind];

			//define one-dimensional cpml parameter arrays 
			cpml_b_ex_xp[ncells_ind] = exp((-c.getDeltaT() / EPS0)*((sigma_pex_xp[ncells_ind] / kappa_ex_xp[ncells_ind]) + alpha_ex_xp[ncells_ind]));
			cpml_a_ex_xp[ncells_ind] = (1 / c.getDeltaX())*(cpml_b_ex_xp[ncells_ind] - 1.0)* sigma_pex_xp[ncells_ind] / (kappa_ex_xp[ncells_ind] * (sigma_pex_xp[ncells_ind] + kappa_ex_xp[ncells_ind] * alpha_ex_xp[ncells_ind]));
			cpml_b_mx_xp[ncells_ind] = exp((-c.getDeltaT() / MU0)*((sigma_pmx_xp[ncells_ind] / kappa_mx_xp[ncells_ind]) + alpha_mx_xp[ncells_ind]));
			cpml_a_mx_xp[ncells_ind] = (1 / c.getDeltaX())*(cpml_b_mx_xp[ncells_ind] - 1.0)*sigma_pmx_xp[ncells_ind] / (kappa_mx_xp[ncells_ind] * (sigma_pmx_xp[ncells_ind] + kappa_mx_xp[ncells_ind] * alpha_mx_xp[ncells_ind]));
		}

		//Create and initialize 2D cpml convolution parameters 
		Psi_eyx_xp = gen3DArray<double>(ncells, ps.getNY(), ps.getNZ() + 1, 0.0);
		Psi_ezx_xp = gen3DArray<double>(ncells, ps.getNY() + 1, ps.getNZ(), 0.0);
		Psi_hyx_xp = gen3DArray<double>(ncells, ps.getNY() + 1, ps.getNZ(), 0.0);
		Psi_hzx_xp = gen3DArray<double>(ncells, ps.getNY(), ps.getNZ() + 1, 0.0);

		//Create and initialize 2D cpml convolution coefficients

		CPsi_eyx_xp = gen3DArray<double>(ncells, ps.getNY(), ps.getNZ() + 1, 0.0);
		CPsi_hzx_xp = gen3DArray<double>(ncells, ps.getNY(), ps.getNZ() + 1, 0.0);
		CPsi_ezx_xp = gen3DArray<double>(ncells, ps.getNY() + 1, ps.getNZ(), 0.0);
		CPsi_hyx_xp = gen3DArray<double>(ncells, ps.getNY() + 1, ps.getNZ(), 0.0);

		for (int i = 0; i<ncells; i++){
			for (int j = 0; j<ps.getNY() + 1; j++){
				for (int k = 0; k<ps.getNZ() + 1; k++){
					if (j<ps.getNY()){
						CPsi_eyx_xp[i][j][k] = EM.getCeyhz(ps.getNX() - ncells + i, j, k)*c.getDeltaX();
						EM.setCeyhz(ps.getNX() - ncells + i, j, k, EM.getCeyhz(ps.getNX() - ncells + i, j, k) / kappa_ex_xp[i]);
						CPsi_hzx_xp[i][j][k] = EM.getChzey(ps.getNX() - ncells + i, j, k)*c.getDeltaX();
						EM.setChzey(ps.getNX() - ncells + i, j, k, EM.getChzey(ps.getNX() - ncells + i, j, k) / kappa_mx_xp[i]);
					}
					if (k<ps.getNZ()){
						CPsi_ezx_xp[i][j][k] = EM.getCezhy(ps.getNX() - ncells + i, j, k)*c.getDeltaX();
						EM.setCezhy(ps.getNX() - ncells + i, j, k, EM.getCezhy(ps.getNX() - ncells + i, j, k) / kappa_ex_xp[i]);
						CPsi_hyx_xp[i][j][k] = EM.getChyez(ps.getNX() - ncells + i, j, k)*c.getDeltaX();
						EM.setChyez(ps.getNX() - ncells + i, j, k, EM.getChyez(ps.getNX() - ncells + i, j, k) / kappa_mx_xp[i]);
					}
				}
			}
		}
	}
}

void PMLmedia::initCPMLboundaryYn(){
	//Initialize cpml for yn region
	if (b.getCPMLyn()){
		int order = b.getOrder(); //order of the polynomial distribution
		double sigmaFactor = b.getSigmaFactor();
		double kappaMax = b.getKappaMax();
		double alphaMin = b.getAlphaMax();
		double alphaMax = b.getAlphaMax();
		double sigmaMax;
		double *rho_e_yn, *rho_m_yn;
		int ncells;
		//define one-dimensional temporary cpml parameter arrays 
		sigmaMax = sigmaFactor*(order + 1) / (150 * PI*c.getDeltaY());
		ncells = b.getCellCountYn();

		rho_e_yn = gen1DArray<double>(ncells, 0.0);
		rho_m_yn = gen1DArray<double>(ncells, 0.0);
		sigma_pey_yn = gen1DArray<double>(ncells, 0.0);
		sigma_pmy_yn = gen1DArray<double>(ncells, 0.0);
		kappa_ey_yn = gen1DArray<double>(ncells, 0.0);
		kappa_my_yn = gen1DArray<double>(ncells, 0.0);
		alpha_ey_yn = gen1DArray<double>(ncells, 0.0);
		alpha_my_yn = gen1DArray<double>(ncells, 0.0);
		cpml_b_ey_yn = gen1DArray<double>(ncells, 0.0);
		cpml_a_ey_yn = gen1DArray<double>(ncells, 0.0);
		cpml_b_my_yn = gen1DArray<double>(ncells, 0.0);
		cpml_a_my_yn = gen1DArray<double>(ncells, 0.0);

		for (int ncells_ind = 0; ncells_ind<ncells; ncells_ind++){
			rho_e_yn[ncells_ind] = (((double)ncells - (double)ncells_ind) - 0.75) / ((double)ncells);
			rho_m_yn[ncells_ind] = (((double)ncells - (double)ncells_ind) - 0.25) / ((double)ncells);

			sigma_pey_yn[ncells_ind] = 1;
			sigma_pmy_yn[ncells_ind] = 1;

			int p_order_ind;
			for (p_order_ind = 1; p_order_ind <= order; p_order_ind++){
				sigma_pey_yn[ncells_ind] = sigma_pey_yn[ncells_ind] * rho_e_yn[ncells_ind];
				sigma_pmy_yn[ncells_ind] = sigma_pmy_yn[ncells_ind] * rho_m_yn[ncells_ind];
			}

			kappa_ey_yn[ncells_ind] = sigma_pey_yn[ncells_ind];
			kappa_my_yn[ncells_ind] = sigma_pmy_yn[ncells_ind];

			sigma_pey_yn[ncells_ind] = sigmaMax*sigma_pey_yn[ncells_ind];
			sigma_pmy_yn[ncells_ind] = sigmaMax*sigma_pmy_yn[ncells_ind];

			kappa_ey_yn[ncells_ind] = 1 + (kappaMax - 1)*kappa_ey_yn[ncells_ind];
			kappa_my_yn[ncells_ind] = 1 + (kappaMax - 1)*kappa_my_yn[ncells_ind];

			sigma_pmy_yn[ncells_ind] = (MU0 / EPS0)*sigma_pmy_yn[ncells_ind];
			alpha_ey_yn[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_e_yn[ncells_ind]);
			alpha_my_yn[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_m_yn[ncells_ind]);
			alpha_my_yn[ncells_ind] = (MU0 / EPS0)*alpha_my_yn[ncells_ind];

			//define one-dimensional cpml parameter arrays 
			cpml_b_ey_yn[ncells_ind] = exp((-c.getDeltaT() / EPS0)*((sigma_pey_yn[ncells_ind] / kappa_ey_yn[ncells_ind]) + alpha_ey_yn[ncells_ind]));
			cpml_a_ey_yn[ncells_ind] = (1 / c.getDeltaY())*(cpml_b_ey_yn[ncells_ind] - 1.0)* sigma_pey_yn[ncells_ind] / (kappa_ey_yn[ncells_ind] * (sigma_pey_yn[ncells_ind] + kappa_ey_yn[ncells_ind] * alpha_ey_yn[ncells_ind]));
			cpml_b_my_yn[ncells_ind] = exp((-c.getDeltaT() / MU0)*((sigma_pmy_yn[ncells_ind] / kappa_my_yn[ncells_ind]) + alpha_my_yn[ncells_ind]));
			cpml_a_my_yn[ncells_ind] = (1 / c.getDeltaY())*(cpml_b_my_yn[ncells_ind] - 1.0)*sigma_pmy_yn[ncells_ind] / (kappa_my_yn[ncells_ind] * (sigma_pmy_yn[ncells_ind] + kappa_my_yn[ncells_ind] * alpha_my_yn[ncells_ind]));
		}

		//Create and initialize 2D cpml convolution parameters 
		Psi_ezy_yn = gen3DArray<double>(ps.getNX() + 1, ncells, ps.getNZ(), 0.0);
		Psi_exy_yn = gen3DArray<double>(ps.getNX(), ncells, ps.getNZ() + 1, 0.0);
		Psi_hzy_yn = gen3DArray<double>(ps.getNX(), ncells, ps.getNZ() + 1, 0.0);
		Psi_hxy_yn = gen3DArray<double>(ps.getNX() + 1, ncells, ps.getNZ(), 0.0);

		//Create and initialize 2D cpml convolution coefficients
		CPsi_ezy_yn = gen3DArray<double>(ps.getNX() + 1, ncells, ps.getNZ(), 0.0);
		CPsi_hxy_yn = gen3DArray<double>(ps.getNX() + 1, ncells, ps.getNZ(), 0.0);
		CPsi_exy_yn = gen3DArray<double>(ps.getNX(), ncells, ps.getNZ() + 1, 0.0);
		CPsi_hzy_yn = gen3DArray<double>(ps.getNX(), ncells, ps.getNZ() + 1, 0.0);

		for (int i = 0; i<ps.getNX() + 1; i++){
			for (int j = 0; j<ncells; j++){
				for (int k = 0; k<ps.getNZ() + 1; k++){
					if (i<ps.getNX()){
						CPsi_exy_yn[i][j][k] = EM.getCexhz(i, j + 1, k)*c.getDeltaY();
						EM.setCexhz(i, j + 1, k, EM.getCexhz(i, j + 1, k) / kappa_ey_yn[j]);
						CPsi_hzy_yn[i][j][k] = EM.getChzex(i, j, k)*c.getDeltaY();
						EM.setChzex(i, j, k, EM.getChzex(i, j, k) / kappa_my_yn[j]);

					}
					if (k<ps.getNZ()){
						CPsi_hxy_yn[i][j][k] = EM.getChxez(i, j, k)*c.getDeltaY();
						EM.setChxez(i, j, k, EM.getChxez(i, j, k) / kappa_my_yn[j]);
						CPsi_ezy_yn[i][j][k] = EM.getCezhx(i, j + 1, k)*c.getDeltaY();
						EM.setCezhx(i, j + 1, k, EM.getCezhx(i, j + 1, k) / kappa_ey_yn[j]);

					}
				}
			}
		}
	}
}

void PMLmedia::initCPMLboundaryYp(){
	//Initialize cpml for yp region
	if (b.getCPMLyp()){
		int order = b.getOrder(); //order of the polynomial distribution
		double sigmaFactor = b.getSigmaFactor();
		double kappaMax = b.getKappaMax();
		double alphaMin = b.getAlphaMax();
		double alphaMax = b.getAlphaMax();
		double sigmaMax;
		int ncells;
		double *rho_e_yp, *rho_m_yp;

		//define one-dimensional temporary cpml parameter arrays 
		sigmaMax = sigmaFactor*(order + 1) / (150 * PI*c.getDeltaY());
		ncells = b.getCellCountYp();

		rho_e_yp = gen1DArray<double>(ncells, 0.0);
		rho_m_yp = gen1DArray<double>(ncells, 0.0);
		sigma_pey_yp = gen1DArray<double>(ncells, 0.0);
		sigma_pmy_yp = gen1DArray<double>(ncells, 0.0);
		kappa_ey_yp = gen1DArray<double>(ncells, 0.0);
		kappa_my_yp = gen1DArray<double>(ncells, 0.0);
		alpha_ey_yp = gen1DArray<double>(ncells, 0.0);
		alpha_my_yp = gen1DArray<double>(ncells, 0.0);
		cpml_b_ey_yp = gen1DArray<double>(ncells, 0.0);
		cpml_a_ey_yp = gen1DArray<double>(ncells, 0.0);
		cpml_b_my_yp = gen1DArray<double>(ncells, 0.0);
		cpml_a_my_yp = gen1DArray<double>(ncells, 0.0);

		for (int ncells_ind = 0; ncells_ind<ncells; ncells_ind++){
			rho_e_yp[ncells_ind] = (((double)ncells_ind + 1) - 0.75) / ((double)ncells);
			rho_m_yp[ncells_ind] = (((double)ncells_ind + 1) - 0.25) / ((double)ncells);

			sigma_pey_yp[ncells_ind] = 1;
			sigma_pmy_yp[ncells_ind] = 1;

			int p_order_ind;
			for (p_order_ind = 1; p_order_ind <= order; p_order_ind++){
				sigma_pey_yp[ncells_ind] = sigma_pey_yp[ncells_ind] * rho_e_yp[ncells_ind];
				sigma_pmy_yp[ncells_ind] = sigma_pmy_yp[ncells_ind] * rho_m_yp[ncells_ind];
			}
			kappa_ey_yp[ncells_ind] = sigma_pey_yp[ncells_ind];
			kappa_my_yp[ncells_ind] = sigma_pmy_yp[ncells_ind];

			sigma_pey_yp[ncells_ind] = sigmaMax*sigma_pey_yp[ncells_ind];
			sigma_pmy_yp[ncells_ind] = sigmaMax*sigma_pmy_yp[ncells_ind];

			kappa_ey_yp[ncells_ind] = 1 + (kappaMax - 1)*kappa_ey_yp[ncells_ind];
			kappa_my_yp[ncells_ind] = 1 + (kappaMax - 1)*kappa_my_yp[ncells_ind];

			sigma_pmy_yp[ncells_ind] = (MU0 / EPS0)*sigma_pmy_yp[ncells_ind];
			alpha_ey_yp[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_e_yp[ncells_ind]);
			alpha_my_yp[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_m_yp[ncells_ind]);
			alpha_my_yp[ncells_ind] = (MU0 / EPS0)*alpha_my_yp[ncells_ind];

			//define one-dimensional cpml parameter arrays 
			cpml_b_ey_yp[ncells_ind] = exp((-c.getDeltaT() / EPS0)*((sigma_pey_yp[ncells_ind] / kappa_ey_yp[ncells_ind]) + alpha_ey_yp[ncells_ind]));
			cpml_a_ey_yp[ncells_ind] = (1 / c.getDeltaY())*(cpml_b_ey_yp[ncells_ind] - 1.0)* sigma_pey_yp[ncells_ind] / (kappa_ey_yp[ncells_ind] * (sigma_pey_yp[ncells_ind] + kappa_ey_yp[ncells_ind] * alpha_ey_yp[ncells_ind]));
			cpml_b_my_yp[ncells_ind] = exp((-c.getDeltaT() / MU0)*((sigma_pmy_yp[ncells_ind] / kappa_my_yp[ncells_ind]) + alpha_my_yp[ncells_ind]));
			cpml_a_my_yp[ncells_ind] = (1 / c.getDeltaY())*(cpml_b_my_yp[ncells_ind] - 1.0)*sigma_pmy_yp[ncells_ind] / (kappa_my_yp[ncells_ind] * (sigma_pmy_yp[ncells_ind] + kappa_my_yp[ncells_ind] * alpha_my_yp[ncells_ind]));
		}

		//Create and initialize 2D cpml convolution parameters 
		Psi_ezy_yp = gen3DArray<double>(ps.getNX() + 1, ncells, ps.getNZ(), 0.0);
		Psi_exy_yp = gen3DArray<double>(ps.getNX(), ncells, ps.getNZ() + 1, 0.0);
		Psi_hzy_yp = gen3DArray<double>(ps.getNX(), ncells, ps.getNZ() + 1, 0.0);
		Psi_hxy_yp = gen3DArray<double>(ps.getNX() + 1, ncells, ps.getNZ(), 0.0);

		//Create and initialize 2D cpml convolution coefficients

		CPsi_exy_yp = gen3DArray<double>(ps.getNX(), ncells, ps.getNZ() + 1, 0.0);
		CPsi_hzy_yp = gen3DArray<double>(ps.getNX(), ncells, ps.getNZ() + 1, 0.0);
		CPsi_ezy_yp = gen3DArray<double>(ps.getNX() + 1, ncells, ps.getNZ(), 0.0);
		CPsi_hxy_yp = gen3DArray<double>(ps.getNX() + 1, ncells, ps.getNZ(), 0.0);

		for (int i = 0; i<ps.getNX() + 1; i++){
			for (int j = 0; j<ncells; j++){
				for (int k = 0; k<ps.getNZ() + 1; k++){
					if (i<ps.getNX()){
						CPsi_exy_yp[i][j][k] = EM.getCexhz(i, ps.getNY() - ncells + j, k)*c.getDeltaY();
						EM.setCexhz(i, ps.getNY() - ncells + j, k, EM.getCexhz(i, ps.getNY() - ncells + j, k) / kappa_ey_yp[j]);
						CPsi_hzy_yp[i][j][k] = EM.getChzex(i, ps.getNY() - ncells + j, k)*c.getDeltaY();
						EM.setChzex(i, ps.getNY() - ncells + j, k, EM.getChzex(i, ps.getNY() - ncells + j, k) / kappa_my_yp[j]);
					}
					if (k<ps.getNZ()){
						CPsi_ezy_yp[i][j][k] = EM.getCezhx(i, ps.getNY() - ncells + j, k)*c.getDeltaY();
						EM.setCezhx(i, ps.getNY() - ncells + j, k, EM.getCezhx(i, ps.getNY() - ncells + j, k) / kappa_ey_yp[j]);
						CPsi_hxy_yp[i][j][k] = EM.getChxez(i, ps.getNY() - ncells + j, k)*c.getDeltaY();
						EM.setChxez(i, ps.getNY() - ncells + j, k, EM.getChxez(i, ps.getNY() - ncells + j, k) / kappa_my_yp[j]);
					}
				}
			}
		}
	}
}

void PMLmedia::initCPMLboundaryZn(){
	//Initialize cpml for zn region
	if (b.getCPMLzn()){
		int order = b.getOrder(); //order of the polynomial distribution
		double sigmaFactor = b.getSigmaFactor();
		double kappaMax = b.getKappaMax();
		double alphaMin = b.getAlphaMax();
		double alphaMax = b.getAlphaMax();
		double sigmaMax;
		int ncells;
		double *rho_e_zn, *rho_m_zn;

		//define one-dimensional temporary cpml parameter arrays 
		sigmaMax = sigmaFactor*(order + 1) / (150 * PI*c.getDeltaZ());
		ncells = b.getCellCountZn();

		rho_e_zn = gen1DArray<double>(ncells, 0.0);
		rho_m_zn = gen1DArray<double>(ncells, 0.0);
		sigma_pez_zn = gen1DArray<double>(ncells, 0.0);
		sigma_pmz_zn = gen1DArray<double>(ncells, 0.0);
		kappa_ez_zn = gen1DArray<double>(ncells, 0.0);
		kappa_mz_zn = gen1DArray<double>(ncells, 0.0);
		alpha_ez_zn = gen1DArray<double>(ncells, 0.0);
		alpha_mz_zn = gen1DArray<double>(ncells, 0.0);
		cpml_b_ez_zn = gen1DArray<double>(ncells, 0.0);
		cpml_a_ez_zn = gen1DArray<double>(ncells, 0.0);
		cpml_b_mz_zn = gen1DArray<double>(ncells, 0.0);
		cpml_a_mz_zn = gen1DArray<double>(ncells, 0.0);

		for (int ncells_ind = 0; ncells_ind<ncells; ncells_ind++){
			rho_e_zn[ncells_ind] = (((double)ncells - (double)ncells_ind) - 0.75) / ((double)ncells);
			rho_m_zn[ncells_ind] = (((double)ncells - (double)ncells_ind) - 0.25) / ((double)ncells);

			sigma_pez_zn[ncells_ind] = 1;
			sigma_pmz_zn[ncells_ind] = 1;

			int p_order_ind;
			for (p_order_ind = 1; p_order_ind <= order; p_order_ind++){
				sigma_pez_zn[ncells_ind] = sigma_pez_zn[ncells_ind] * rho_e_zn[ncells_ind];
				sigma_pmz_zn[ncells_ind] = sigma_pmz_zn[ncells_ind] * rho_m_zn[ncells_ind];
			}

			kappa_ez_zn[ncells_ind] = sigma_pez_zn[ncells_ind];
			kappa_mz_zn[ncells_ind] = sigma_pmz_zn[ncells_ind];

			sigma_pez_zn[ncells_ind] = sigmaMax*sigma_pez_zn[ncells_ind];
			sigma_pmz_zn[ncells_ind] = sigmaMax*sigma_pmz_zn[ncells_ind];

			kappa_ez_zn[ncells_ind] = 1 + (kappaMax - 1)*kappa_ez_zn[ncells_ind];
			kappa_mz_zn[ncells_ind] = 1 + (kappaMax - 1)*kappa_mz_zn[ncells_ind];

			sigma_pmz_zn[ncells_ind] = (MU0 / EPS0)*sigma_pmz_zn[ncells_ind];
			alpha_ez_zn[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_e_zn[ncells_ind]);
			alpha_mz_zn[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_m_zn[ncells_ind]);
			alpha_mz_zn[ncells_ind] = (MU0 / EPS0)*alpha_mz_zn[ncells_ind];

			//define one-dimensional cpml parameter arrays 
			cpml_b_ez_zn[ncells_ind] = exp((-c.getDeltaT() / EPS0)*((sigma_pez_zn[ncells_ind] / kappa_ez_zn[ncells_ind]) + alpha_ez_zn[ncells_ind]));
			cpml_a_ez_zn[ncells_ind] = (1 / c.getDeltaZ())*(cpml_b_ez_zn[ncells_ind] - 1.0)* sigma_pez_zn[ncells_ind] / (kappa_ez_zn[ncells_ind] * (sigma_pez_zn[ncells_ind] + kappa_ez_zn[ncells_ind] * alpha_ez_zn[ncells_ind]));
			cpml_b_mz_zn[ncells_ind] = exp((-c.getDeltaT() / MU0)*((sigma_pmz_zn[ncells_ind] / kappa_mz_zn[ncells_ind]) + alpha_mz_zn[ncells_ind]));
			cpml_a_mz_zn[ncells_ind] = (1 / c.getDeltaZ())*(cpml_b_mz_zn[ncells_ind] - 1.0)*sigma_pmz_zn[ncells_ind] / (kappa_mz_zn[ncells_ind] * (sigma_pmz_zn[ncells_ind] + kappa_mz_zn[ncells_ind] * alpha_mz_zn[ncells_ind]));
		}
		//Create and initialize 2D cpml convolution parameters 
		Psi_eyz_zn = gen3DArray<double>(ps.getNX() + 1, ps.getNY(), ncells, 0.0);
		Psi_exz_zn = gen3DArray<double>(ps.getNX(), ps.getNY() + 1, ncells, 0.0);
		Psi_hyz_zn = gen3DArray<double>(ps.getNX(), ps.getNY() + 1, ncells, 0.0);
		Psi_hxz_zn = gen3DArray<double>(ps.getNX() + 1, ps.getNY(), ncells, 0.0);

		//Create and initialize 2D cpml convolution coefficients

		CPsi_eyz_zn = gen3DArray<double>(ps.getNX() + 1, ps.getNY(), ncells, 0.0);
		CPsi_hxz_zn = gen3DArray<double>(ps.getNX() + 1, ps.getNY(), ncells, 0.0);
		CPsi_exz_zn = gen3DArray<double>(ps.getNX(), ps.getNY() + 1, ncells, 0.0);
		CPsi_hyz_zn = gen3DArray<double>(ps.getNX(), ps.getNY() + 1, ncells, 0.0);

		for (int i = 0; i<ps.getNX() + 1; i++){
			for (int j = 0; j<ps.getNY() + 1; j++){
				for (int k = 0; k<ncells; k++){
					if (j<ps.getNY()){
						CPsi_eyz_zn[i][j][k] = EM.getCeyhx(i, j, k + 1)*c.getDeltaZ();
						EM.setCeyhx(i, j, k + 1, EM.getCeyhx(i, j, k + 1) / kappa_ez_zn[k]);
						CPsi_hxz_zn[i][j][k] = EM.getChxey(i, j, k)*c.getDeltaZ();
						EM.setChxey(i, j, k, EM.getChxey(i, j, k) / kappa_mz_zn[k]);
					}
					if (i<ps.getNX()){
						CPsi_exz_zn[i][j][k] = EM.getCexhy(i, j, k + 1)*c.getDeltaZ();
						EM.setCexhy(i, j, k + 1, EM.getCexhy(i, j, k + 1) / kappa_ez_zn[k]);
						CPsi_hyz_zn[i][j][k] = EM.getChyex(i, j, k)*c.getDeltaZ();
						EM.setChyex(i, j, k, EM.getChyex(i, j, k) / kappa_mz_zn[k]);
					}
				}
			}
		}
	}
}

void PMLmedia::initCPMLboundaryZp(){
	//Initialize cpml for zp region
	if (b.getCPMLzp()){
		int order = b.getOrder(); //order of the polynomial distribution
		double sigmaFactor = b.getSigmaFactor();
		double kappaMax = b.getKappaMax();
		double alphaMin = b.getAlphaMax();
		double alphaMax = b.getAlphaMax();
		double sigmaMax;
		int ncells;
		double *rho_e_zp, *rho_m_zp;

		//define one-dimensional temporary cpml parameter arrays 
		sigmaMax = sigmaFactor*(order + 1) / (150 * PI*c.getDeltaZ());
		ncells = b.getCellCountZp();


		rho_e_zp = gen1DArray<double>(ncells, 0.0);
		rho_m_zp = gen1DArray<double>(ncells, 0.0);
		sigma_pez_zp = gen1DArray<double>(ncells, 0.0);
		sigma_pmz_zp = gen1DArray<double>(ncells, 0.0);
		kappa_ez_zp = gen1DArray<double>(ncells, 0.0);
		kappa_mz_zp = gen1DArray<double>(ncells, 0.0);
		alpha_ez_zp = gen1DArray<double>(ncells, 0.0);
		alpha_mz_zp = gen1DArray<double>(ncells, 0.0);
		cpml_b_ez_zp = gen1DArray<double>(ncells, 0.0);
		cpml_a_ez_zp = gen1DArray<double>(ncells, 0.0);
		cpml_b_mz_zp = gen1DArray<double>(ncells, 0.0);
		cpml_a_mz_zp = gen1DArray<double>(ncells, 0.0);

		for (int ncells_ind = 0; ncells_ind<ncells; ncells_ind++){
			rho_e_zp[ncells_ind] = (((double)ncells_ind + 1) - 0.75) / ((double)ncells);
			rho_m_zp[ncells_ind] = (((double)ncells_ind + 1) - 0.25) / ((double)ncells);

			sigma_pez_zp[ncells_ind] = 1;
			sigma_pmz_zp[ncells_ind] = 1;

			int p_order_ind;
			for (p_order_ind = 1; p_order_ind <= order; p_order_ind++){
				sigma_pez_zp[ncells_ind] = sigma_pez_zp[ncells_ind] * rho_e_zp[ncells_ind];
				sigma_pmz_zp[ncells_ind] = sigma_pmz_zp[ncells_ind] * rho_m_zp[ncells_ind];
			}
			kappa_ez_zp[ncells_ind] = sigma_pez_zp[ncells_ind];
			kappa_mz_zp[ncells_ind] = sigma_pmz_zp[ncells_ind];

			sigma_pez_zp[ncells_ind] = sigmaMax*sigma_pez_zp[ncells_ind];
			sigma_pmz_zp[ncells_ind] = sigmaMax*sigma_pmz_zp[ncells_ind];

			kappa_ez_zp[ncells_ind] = 1 + (kappaMax - 1)*kappa_ez_zp[ncells_ind];
			kappa_mz_zp[ncells_ind] = 1 + (kappaMax - 1)*kappa_mz_zp[ncells_ind];

			sigma_pmz_zp[ncells_ind] = (MU0 / EPS0)*sigma_pmz_zp[ncells_ind];
			alpha_ez_zp[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_e_zp[ncells_ind]);
			alpha_mz_zp[ncells_ind] = alphaMin + (alphaMax - alphaMin)*(1 - rho_m_zp[ncells_ind]);
			alpha_mz_zp[ncells_ind] = (MU0 / EPS0)*alpha_mz_zp[ncells_ind];

			//define one-dimensional cpml parameter arrays 
			cpml_b_ez_zp[ncells_ind] = exp((-c.getDeltaT() / EPS0)*((sigma_pez_zp[ncells_ind] / kappa_ez_zp[ncells_ind]) + alpha_ez_zp[ncells_ind]));
			cpml_a_ez_zp[ncells_ind] = (1 / c.getDeltaZ())*(cpml_b_ez_zp[ncells_ind] - 1.0)* sigma_pez_zp[ncells_ind] / (kappa_ez_zp[ncells_ind] * (sigma_pez_zp[ncells_ind] + kappa_ez_zp[ncells_ind] * alpha_ez_zp[ncells_ind]));
			cpml_b_mz_zp[ncells_ind] = exp((-c.getDeltaT() / MU0)*((sigma_pmz_zp[ncells_ind] / kappa_mz_zp[ncells_ind]) + alpha_mz_zp[ncells_ind]));
			cpml_a_mz_zp[ncells_ind] = (1 / c.getDeltaZ())*(cpml_b_mz_zp[ncells_ind] - 1.0)*sigma_pmz_zp[ncells_ind] / (kappa_mz_zp[ncells_ind] * (sigma_pmz_zp[ncells_ind] + kappa_mz_zp[ncells_ind] * alpha_mz_zp[ncells_ind]));
		}

		//Create and initialize 2D cpml convolution parameters 
		Psi_exz_zp = gen3DArray<double>(ps.getNX(), ps.getNY() + 1, ncells, 0.0);
		Psi_eyz_zp = gen3DArray<double>(ps.getNX() + 1, ps.getNY(), ncells, 0.0);
		Psi_hxz_zp = gen3DArray<double>(ps.getNX() + 1, ps.getNY(), ncells, 0.0);
		Psi_hyz_zp = gen3DArray<double>(ps.getNX(), ps.getNY() + 1, ncells, 0.0);

		//Create and initialize 2D cpml convolution coefficients

		CPsi_eyz_zp = gen3DArray<double>(ps.getNX() + 1, ps.getNY(), ncells, 0.0);
		CPsi_hxz_zp = gen3DArray<double>(ps.getNX() + 1, ps.getNY(), ncells, 0.0);
		CPsi_exz_zp = gen3DArray<double>(ps.getNX(), ps.getNY() + 1, ncells, 0.0);
		CPsi_hyz_zp = gen3DArray<double>(ps.getNX(), ps.getNY() + 1, ncells, 0.0);

		for (int i = 0; i<ps.getNX() + 1; i++){
			for (int j = 0; j<ps.getNY() + 1; j++){
				for (int k = 0; k<ncells; k++){
					if (j<ps.getNY()){
						CPsi_eyz_zp[i][j][k] = EM.getCeyhx(i, j, ps.getNZ() - ncells + k)*c.getDeltaZ();
						EM.setCeyhx(i, j, ps.getNZ() - ncells + k, EM.getCeyhx(i, j, ps.getNZ() - ncells + k) / kappa_ez_zp[k]);
						CPsi_hxz_zp[i][j][k] = EM.getChxey(i, j, ps.getNZ() - ncells + k)*c.getDeltaZ();
						EM.setChxey(i, j, ps.getNZ() - ncells + k, EM.getChxey(i, j, ps.getNZ() - ncells + k) / kappa_mz_zp[k]);
					}
					if (i<ps.getNX()){
						CPsi_exz_zp[i][j][k] = EM.getCexhy(i, j, ps.getNZ() - ncells + k)*c.getDeltaZ();
						EM.setCexhy(i, j, ps.getNZ() - ncells + k, EM.getCexhy(i, j, ps.getNZ() - ncells + k) / kappa_ez_zp[k]);
						CPsi_hyz_zp[i][j][k] = EM.getChyex(i, j, ps.getNZ() - ncells + k)*c.getDeltaZ();
						EM.setChyex(i, j, ps.getNZ() - ncells + k, EM.getChyex(i, j, ps.getNZ() - ncells + k) / kappa_mz_zp[k]);
					}
				}
			}
		}
	}
}

void PMLmedia::initAllCPMLboundary(){
	if (b.isAnySideCPML()) {
		//Initialize CPML boundary condition
		initCPMLboundaryXn();
		initCPMLboundaryXp();
		initCPMLboundaryYn();
		initCPMLboundaryYp();
		initCPMLboundaryZn();
		initCPMLboundaryZp();
	}
}

void PMLmedia::applyCPML2Hfield(){
	for (int i = 0; i<b.getCellCountXn(); i++){
		for (int j = 0; j<ps.getNY() + 1; j++){
			for (int k = 0; k<ps.getNZ(); k++){
				Psi_hyx_xn[i][j][k] = cpml_b_mx_xn[i] * Psi_hyx_xn[i][j][k] + cpml_a_mx_xn[i] * (Field::getEZ(i + 1, j, k) - Field::getEZ(i, j, k));
				Field::setHY(i, j, k, Field::getHY(i, j, k) + CPsi_hyx_xn[i][j][k] * Psi_hyx_xn[i][j][k]);
			}
		}
	}

	//is_cpml_xn == TRUE && j<ny
	for (int i = 0; i<b.getCellCountXn(); i++){
		for (int j = 0; j<ps.getNY(); j++){
			for (int k = 0; k<ps.getNZ() + 1; k++){
				Psi_hzx_xn[i][j][k] = cpml_b_mx_xn[i] * Psi_hzx_xn[i][j][k] + cpml_a_mx_xn[i] * (Field::getEY(i + 1, j, k) - Field::getEY(i, j, k));
				Field::setHZ(i, j, k, Field::getHZ(i, j, k) + CPsi_hzx_xn[i][j][k] * Psi_hzx_xn[i][j][k]);
			}
		}
	}

	//is_cpml_xp == TRUE && k<nz
	for (int i = 0; i<b.getCellCountXp(); i++){
		for (int j = 0; j<ps.getNY() + 1; j++){
			for (int k = 0; k<ps.getNZ(); k++){
				Psi_hyx_xp[i][j][k] = cpml_b_mx_xp[i] * Psi_hyx_xp[i][j][k] + cpml_a_mx_xp[i] * (Field::getEZ(i + (ps.getNX() - b.getCellCountXp()) + 1, j, k) - Field::getEZ(i + (ps.getNX() - b.getCellCountXp()), j, k));
				Field::setHY((ps.getNX() - b.getCellCountXp()) + i, j, k, Field::getHY((ps.getNX() - b.getCellCountXp()) + i, j, k) + CPsi_hyx_xp[i][j][k] * Psi_hyx_xp[i][j][k]);
			}
		}
	}

	//is_cpml_xp == TRUE && j<ny
	for (int i = 0; i<b.getCellCountXp(); i++){
		for (int j = 0; j<ps.getNY(); j++){
			for (int k = 0; k<ps.getNZ() + 1; k++){
				Psi_hzx_xp[i][j][k] = cpml_b_mx_xp[i] * Psi_hzx_xp[i][j][k] + cpml_a_mx_xp[i] * (Field::getEY(i + (ps.getNX() - b.getCellCountXp()) + 1, j, k) - Field::getEY(i + (ps.getNX() - b.getCellCountXp()), j, k));
				Field::setHZ((ps.getNX() - b.getCellCountXp()) + i, j, k, Field::getHZ((ps.getNX() - b.getCellCountXp()) + i, j, k) + CPsi_hzx_xp[i][j][k] * Psi_hzx_xp[i][j][k]);
			}
		}
	}

	//is_cpml_yn == TRUE && i<nx
	for (int i = 0; i<ps.getNX(); i++){
		for (int j = 0; j<b.getCellCountYn(); j++){
			for (int k = 0; k<ps.getNZ() + 1; k++){
				Psi_hzy_yn[i][j][k] = cpml_b_my_yn[j] * Psi_hzy_yn[i][j][k] + cpml_a_my_yn[j] * (Field::getEX(i, j + 1, k) - Field::getEX(i, j, k));
				Field::setHZ(i, j, k, Field::getHZ(i, j, k) + CPsi_hzy_yn[i][j][k] * Psi_hzy_yn[i][j][k]);
			}
		}
	}

	//is_cpml_yn == TRUE && k<nz
	for (int i = 0; i<ps.getNX() + 1; i++){
		for (int j = 0; j<b.getCellCountYn(); j++){
			for (int k = 0; k<ps.getNZ(); k++){
				Psi_hxy_yn[i][j][k] = cpml_b_my_yn[j] * Psi_hxy_yn[i][j][k] + cpml_a_my_yn[j] * (Field::getEZ(i, j + 1, k) - Field::getEZ(i, j, k));
				Field::setHX(i, j, k, Field::getHX(i, j, k) + CPsi_hxy_yn[i][j][k] * Psi_hxy_yn[i][j][k]);
			}
		}
	}

	//is_cpml_yp == TRUE && i<nx
	for (int i = 0; i<ps.getNX(); i++){
		for (int j = 0; j<b.getCellCountYp(); j++){
			for (int k = 0; k<ps.getNZ() + 1; k++){
				Psi_hzy_yp[i][j][k] = cpml_b_my_yp[j] * Psi_hzy_yp[i][j][k] + cpml_a_my_yp[j] * (Field::getEX(i, j + (ps.getNY() - b.getCellCountYp()) + 1, k) - Field::getEX(i, j + (ps.getNY() - b.getCellCountYp()), k));
				Field::setHZ(i, (ps.getNY() - b.getCellCountYp()) + j, k, Field::getHZ(i, (ps.getNY() - b.getCellCountYp()) + j, k) + CPsi_hzy_yp[i][j][k] * Psi_hzy_yp[i][j][k]);
			}
		}
	}

	//is_cpml_yp == TRUE && k<nz
	for (int i = 0; i<ps.getNX() + 1; i++){
		for (int j = 0; j<b.getCellCountYp(); j++){
			for (int k = 0; k<ps.getNZ(); k++){
				Psi_hxy_yp[i][j][k] = cpml_b_my_yp[j] * Psi_hxy_yp[i][j][k] + cpml_a_my_yp[j] * (Field::getEZ(i, j + (ps.getNY() - b.getCellCountYp()) + 1, k) - Field::getEZ(i, j + (ps.getNY() - b.getCellCountYp()), k));
				Field::setHX(i, (ps.getNY() - b.getCellCountYp()) + j, k, Field::getHX(i, (ps.getNY() - b.getCellCountYp()) + j, k) + CPsi_hxy_yp[i][j][k] * Psi_hxy_yp[i][j][k]);
			}
		}
	}

	//is_cpml_zn == TRUE && j<ny
	for (int i = 0; i<ps.getNX() + 1; i++){
		for (int j = 0; j<ps.getNY(); j++){
			for (int k = 0; k<b.getCellCountZn(); k++){
				Psi_hxz_zn[i][j][k] = cpml_b_mz_zn[k] * Psi_hxz_zn[i][j][k] + cpml_a_mz_zn[k] * (Field::getEY(i, j, k + 1) - Field::getEY(i, j, k));
				Field::setHX(i, j, k, Field::getHX(i, j, k) + CPsi_hxz_zn[i][j][k] * Psi_hxz_zn[i][j][k]);
			}
		}
	}

	//is_cpml_zn == TRUE && i<nx
	for (int i = 0; i<ps.getNX(); i++){
		for (int j = 0; j<ps.getNY() + 1; j++){
			for (int k = 0; k<b.getCellCountZn(); k++){
				Psi_hyz_zn[i][j][k] = cpml_b_mz_zn[k] * Psi_hyz_zn[i][j][k] + cpml_a_mz_zn[k] * (Field::getEX(i, j, k + 1) - Field::getEX(i, j, k));
				Field::setHY(i, j, k, Field::getHY(i, j, k) + CPsi_hyz_zn[i][j][k] * Psi_hyz_zn[i][j][k]);
			}
		}
	}

	//is_cpml_zp ==TRUE && j<ny
	for (int i = 0; i<ps.getNX() + 1; i++){
		for (int j = 0; j<ps.getNY(); j++){
			for (int k = 0; k<b.getCellCountZp(); k++){
				Psi_hxz_zp[i][j][k] = cpml_b_mz_zp[k] * Psi_hxz_zp[i][j][k] + cpml_a_mz_zp[k] * (Field::getEY(i, j, k + (ps.getNZ() - b.getCellCountZp()) + 1) - Field::getEY(i, j, k + (ps.getNZ() - b.getCellCountZp())));
				Field::setHX(i, j, (ps.getNZ() - b.getCellCountZp()) + k, Field::getHX(i, j, (ps.getNZ() - b.getCellCountZp()) + k) + CPsi_hxz_zp[i][j][k] * Psi_hxz_zp[i][j][k]);
			}
		}
	}

	//is_cpml_zp ==TRUE && i<nx
	for (int i = 0; i<ps.getNX(); i++){
		for (int j = 0; j<ps.getNY() + 1; j++){
			for (int k = 0; k<b.getCellCountZp(); k++){
				Psi_hyz_zp[i][j][k] = cpml_b_mz_zp[k] * Psi_hyz_zp[i][j][k] + cpml_a_mz_zp[k] * (Field::getEX(i, j, k + (ps.getNZ() - b.getCellCountZp()) + 1) - Field::getEX(i, j, k + (ps.getNZ() - b.getCellCountZp())));
				Field::setHY(i, j, (ps.getNZ() - b.getCellCountZp()) + k, Field::getHY(i, j, (ps.getNZ() - b.getCellCountZp()) + k) + CPsi_hyz_zp[i][j][k] * Psi_hyz_zp[i][j][k]);
			}
		}
	}

}

void PMLmedia::applyCPML2Efield(){
	int temp;
	for (int i = 0; i<b.getCellCountXn(); i++){
		for (int j = 0; j<ps.getNY(); j++){
			for (int k = 0; k<ps.getNZ() + 1; k++){
				Psi_eyx_xn[i][j][k] = cpml_b_ex_xn[i] * Psi_eyx_xn[i][j][k] + cpml_a_ex_xn[i] * (Field::getHZ(i + 1, j, k) - Field::getHZ(i, j, k));
				Field::setEY(i + 1, j, k, Field::getEY(i + 1, j, k) + CPsi_eyx_xn[i][j][k] * Psi_eyx_xn[i][j][k]);
			}
		}
	}

	//is_cpml_xn == TRUE && k<nz
	for (int i = 0; i<b.getCellCountXn(); i++){
		for (int j = 0; j<ps.getNY() + 1; j++){
			for (int k = 0; k<ps.getNZ(); k++){
				Psi_ezx_xn[i][j][k] = cpml_b_ex_xn[i] * Psi_ezx_xn[i][j][k] + cpml_a_ex_xn[i] * (Field::getHY(i + 1, j, k) - Field::getHY(i, j, k));
				Field::setEZ(i + 1, j, k, Field::getEZ(i + 1, j, k) + CPsi_ezx_xn[i][j][k] * Psi_ezx_xn[i][j][k]);
			}
		}
	}
	//is_cpml_xp == TRUE && j<ny
	temp = ps.getNX() - b.getCellCountXp();
	for (int i = 0; i<b.getCellCountXp(); i++){
		for (int j = 0; j<ps.getNY(); j++){
			for (int k = 0; k<ps.getNZ() + 1; k++){
				Psi_eyx_xp[i][j][k] = cpml_b_ex_xp[i] * Psi_eyx_xp[i][j][k] + cpml_a_ex_xp[i] * (Field::getHZ(i + temp, j, k) - Field::getHZ(i + temp - 1, j, k));
				Field::setEY(temp + i, j, k, Field::getEY(temp + i, j, k) + CPsi_eyx_xp[i][j][k] * Psi_eyx_xp[i][j][k]);
			}
		}
	}

	//is_cpml_xp == TRUE && k<nz
	for (int i = 0; i<b.getCellCountXp(); i++){
		for (int j = 0; j<ps.getNY() + 1; j++){
			for (int k = 0; k<ps.getNZ(); k++){
				Psi_ezx_xp[i][j][k] = cpml_b_ex_xp[i] * Psi_ezx_xp[i][j][k] + cpml_a_ex_xp[i] * (Field::getHY(i + temp, j, k) - Field::getHY(i + temp - 1, j, k));
				Field::setEZ(temp + i, j, k, Field::getEZ(temp + i, j, k) + CPsi_ezx_xp[i][j][k] * Psi_ezx_xp[i][j][k]);
			}
		}
	}

	//is_cpml_yn == TRUE && k<nz
	for (int i = 0; i<ps.getNX() + 1; i++){
		for (int j = 0; j<b.getCellCountYn(); j++){
			for (int k = 0; k<ps.getNZ(); k++){
				Psi_ezy_yn[i][j][k] = cpml_b_ey_yn[j] * Psi_ezy_yn[i][j][k] + cpml_a_ey_yn[j] * (Field::getHX(i, j + 1, k) - Field::getHX(i, j, k));
				Field::setEZ(i, j + 1, k, Field::getEZ(i, j + 1, k) + CPsi_ezy_yn[i][j][k] * Psi_ezy_yn[i][j][k]);
			}
		}
	}

	//is_cpml_yn == TRUE && i<nx
	for (int i = 0; i<ps.getNX(); i++){
		for (int j = 0; j<b.getCellCountYn(); j++){
			for (int k = 0; k<ps.getNZ() + 1; k++){
				Psi_exy_yn[i][j][k] = cpml_b_ey_yn[j] * Psi_exy_yn[i][j][k] + cpml_a_ey_yn[j] * (Field::getHZ(i, j + 1, k) - Field::getHZ(i, j, k));
				Field::setEX(i, j + 1, k, Field::getEX(i, j + 1, k) + CPsi_exy_yn[i][j][k] * Psi_exy_yn[i][j][k]);
			}
		}
	}

	//is_cpml_yp == TRUE && k<nz
	temp = ps.getNY() - b.getCellCountYp();
	for (int i = 0; i<ps.getNX() + 1; i++){
		for (int j = 0; j<b.getCellCountYp(); j++){
			for (int k = 0; k<ps.getNZ(); k++){
				Psi_ezy_yp[i][j][k] = cpml_b_ey_yp[j] * Psi_ezy_yp[i][j][k] + cpml_a_ey_yp[j] * (Field::getHX(i, j + temp, k) - Field::getHX(i, j + temp - 1, k));
				Field::setEZ(i, temp + j, k, Field::getEZ(i, temp + j, k) + CPsi_ezy_yp[i][j][k] * Psi_ezy_yp[i][j][k]);
			}
		}
	}

	//is_cpml_yp == TRUE && i<nx
	for (int i = 0; i<ps.getNX(); i++){
		for (int j = 0; j<b.getCellCountYp(); j++){
			for (int k = 0; k<ps.getNZ() + 1; k++){
				Psi_exy_yp[i][j][k] = cpml_b_ey_yp[j] * Psi_exy_yp[i][j][k] + cpml_a_ey_yp[j] * (Field::getHZ(i, j + temp, k) - Field::getHZ(i, j + temp - 1, k));
				Field::setEX(i, temp + j, k, Field::getEX(i, temp + j, k) + CPsi_exy_yp[i][j][k] * Psi_exy_yp[i][j][k]);
			}
		}
	}

	//is_cpml_zn == TRUE && i<nx
	for (int i = 0; i<ps.getNX(); i++){
		for (int j = 0; j<ps.getNY() + 1; j++){
			for (int k = 0; k<b.getCellCountZn(); k++){
				Psi_exz_zn[i][j][k] = cpml_b_ez_zn[k] * Psi_exz_zn[i][j][k] + cpml_a_ez_zn[k] * (Field::getHY(i, j, k + 1) - Field::getHY(i, j, k));
				Field::setEX(i, j, k + 1, Field::getEX(i, j, k + 1) + CPsi_exz_zn[i][j][k] * Psi_exz_zn[i][j][k]);
			}
		}
	}

	//is_cpml_zn == TRUE && j<ny
	for (int i = 0; i<ps.getNX() + 1; i++){
		for (int j = 0; j<ps.getNY(); j++){
			for (int k = 0; k<b.getCellCountZn(); k++){
				Psi_eyz_zn[i][j][k] = cpml_b_ez_zn[k] * Psi_eyz_zn[i][j][k] + cpml_a_ez_zn[k] * (Field::getHX(i, j, k + 1) - Field::getHX(i, j, k));
				Field::setEY(i, j, k + 1, Field::getEY(i, j, k + 1) + CPsi_eyz_zn[i][j][k] * Psi_eyz_zn[i][j][k]);
			}
		}
	}

	//is_cpml_zp = TRUE && i<nx
	temp = ps.getNZ() - b.getCellCountZp();
	for (int i = 0; i<ps.getNX(); i++){
		for (int j = 0; j<ps.getNY() + 1; j++){
			for (int k = 0; k<b.getCellCountZp(); k++){
				Psi_exz_zp[i][j][k] = cpml_b_ez_zp[k] * Psi_exz_zp[i][j][k] + cpml_a_ez_zp[k] * (Field::getHY(i, j, k + temp) - Field::getHY(i, j, k + temp - 1));
				Field::setEX(i, j, temp + k, Field::getEX(i, j, temp + k) + CPsi_exz_zp[i][j][k] * Psi_exz_zp[i][j][k]);
			}
		}
	}

	//is_cpml_zp = TRUE && j<ny
	for (int i = 0; i<ps.getNX() + 1; i++){
		for (int j = 0; j<ps.getNY(); j++){
			for (int k = 0; k<b.getCellCountZp(); k++){
				Psi_eyz_zp[i][j][k] = cpml_b_ez_zp[k] * Psi_eyz_zp[i][j][k] + cpml_a_ez_zp[k] * (Field::getHX(i, j, k + temp) - Field::getHX(i, j, k + temp - 1));
				Field::setEY(i, j, temp + k, Field::getEY(i, j, temp + k) + CPsi_eyz_zp[i][j][k] * Psi_eyz_zp[i][j][k]);
			}
		}
	}
}
