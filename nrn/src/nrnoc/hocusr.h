extern int node_data(), disconnect();
extern int batch_run(), batch_save();
extern int pt3dclear(), pt3dadd(), n3d(), x3d(), y3d(), z3d(), arc3d(), diam3d();
extern int pt3dinsert(), pt3dremove(), pt3dchange();
extern int define_shape(), pt3dconst(), pt3dstyle();
extern int spine3d(), setSpineArea(), getSpineArea();
extern int area(), ri();
extern int initnrn(), topology(), fadvance(), distance(), finitialize();
extern int fstim(), fstimi();
extern int ion_style(), ion_register(), ion_charge(), nernst(), ghk();
extern int section_owner();
extern int make_mechanism(), make_pointprocess();
extern int nrnpython();

extern int fsyn(), fsyng(), fsyni();

extern int fclamp(), fclampi(), fclampv(), prstim();
extern int fcurrent(), fmatrix(), frecord_init();
extern int issection(), ismembrane(), sectionname(), psection();
extern int pop_section(), push_section(), section_exists();
extern int delete_section();
extern int secondorder, diam_changed, nrn_shape_changed_;
extern double clamp_resist;
extern double celsius;
extern int stoprun;

extern int fit_praxis(), attr_praxis(), pval_praxis(), stop_praxis();

extern int keep_nseg_parm();


extern int nrnallsectionmenu(), nrnallpointmenu(), nrnsecmenu();
extern int nrnglobalmechmenu(), nrnmechmenu(), nrnpointmenu();

extern int this_section(), this_node(), parent_section(), parent_node();
extern int parent_connection(), section_orientation();
static struct {		/* Functions */
	char 	*name;
	int	(*func)();
} function[] = {
"node_data", node_data,
"disconnect", disconnect,
"batch_run", batch_run,
"batch_save", batch_save,
"pt3dclear", pt3dclear,
"pt3dadd", pt3dadd,
"n3d", n3d,
"x3d", x3d,
"y3d", y3d,
"z3d", z3d,
"arc3d", arc3d,
"diam3d", diam3d,
"pt3dinsert", pt3dinsert,
"pt3dremove", pt3dremove,
"pt3dchange", pt3dchange,
"define_shape", define_shape,
"pt3dconst", pt3dconst,
"pt3dstyle", pt3dstyle,
"spine3d", spine3d,
"setSpineArea", setSpineArea,
"getSpineArea", getSpineArea,
"area", area,
"ri", ri,
"initnrn", initnrn,
"topology", topology,
"fadvance", fadvance,
"distance", distance,
"finitialize", finitialize,
"fstim", fstim,
"fstimi", fstimi,
"ion_style", ion_style,
"ion_register", ion_register,
"ion_charge", ion_charge,
"nernst", nernst,
"ghk", ghk,
"section_owner", section_owner,
"make_mechanism", make_mechanism,
"make_pointprocess", make_pointprocess,
"nrnpython", nrnpython,
"fsyn", fsyn,
"fsyng", fsyng,
"fsyni", fsyni,
"fclamp", fclamp,
"fclampi", fclampi,
"fclampv", fclampv,
"prstim", prstim,
"fcurrent", fcurrent,
"fmatrix", fmatrix,
"frecord_init", frecord_init,
"issection", issection,
"ismembrane", ismembrane,
"sectionname", sectionname,
"psection", psection,
"pop_section", pop_section,
"push_section", push_section,
"section_exists", section_exists,
"delete_section", delete_section,
"fit_praxis", fit_praxis,
"attr_praxis", attr_praxis,
"pval_praxis", pval_praxis,
"stop_praxis", stop_praxis,
"keep_nseg_parm", keep_nseg_parm,
"nrnallsectionmenu", nrnallsectionmenu,
"nrnallpointmenu", nrnallpointmenu,
"nrnsecmenu", nrnsecmenu,
"nrnglobalmechmenu", nrnglobalmechmenu,
"nrnmechmenu", nrnmechmenu,
"nrnpointmenu", nrnpointmenu,
"this_section", this_section,
"this_node", this_node,
"parent_section", parent_section,
"parent_node", parent_node,
"parent_connection", parent_connection,
"section_orientation", section_orientation,
0,0
};
static struct {		/* Integer Scalars */
	char 	*name;
	int	*pint;
} scint[] = {
"secondorder", &secondorder,
"diam_changed", &diam_changed,
"nrn_shape_changed_", &nrn_shape_changed_,
"stoprun", &stoprun,
0, 0
};
static struct {		/* Vector integers */
	char 	*name;
	int	*pint;
	int	index1;
} vint[] = {
0,0
};
static struct {		/* Integer Scalars */
	char 	*name;
	float	*pfloat;
} scfloat[] = {
0, 0
};
static struct {		/* Vector integers */
	char 	*name;
	float	*pfloat;
	int	index1;
} vfloat[] = {
0,0,0
};
static struct {		/* Double Scalars */
	char 	*name;
	double	*pdoub;
} scdoub[] = {
"clamp_resist", &clamp_resist,
"celsius", &celsius,
0,0
};
static struct {		/* Vectors */
	char 	*name;
	double	*pdoub;
	int	index1;
} vdoub[] = {
0, 0, 0
};
static struct {		/* Arrays */
	char 	*name;
	double	*pdoub;
	int	index1;
	int 	index2;
} ardoub[] = {
0, 0, 0, 0
};
static struct {		/* triple dimensioned arrays */
	char 	*name;
	double	*pdoub;
	int	index1;
	int 	index2;
	int	index3;
} thredim[] = {
0, 0, 0, 0, 0
};
