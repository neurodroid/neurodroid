/* Created by Language version: 6.2.0 */
/* VECTORIZED */
#include <stdio.h>
#include <math.h>
#include "scoplib.h"
#undef PI
 
#include "md1redef.h"
#include "section.h"
#include "md2redef.h"

#if METHOD3
extern int _method3;
#endif

#undef exp
#define exp hoc_Exp
extern double hoc_Exp();
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define taus _p[0]
#define taum _p[1]
#define ib _p[2]
#define i _p[3]
#define m _p[4]
#define t0 _p[5]
#define v _p[6]
#define _tsav _p[7]
#define _nd_area  *_ppvar[0]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_I();
 static double _hoc_M();
 static double _hoc_firetime();
 static double _hoc_newton1();
 static int _mechtype;
extern int nrn_get_mechtype();
 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 static _hoc_setdata(_vptr) void* _vptr; { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
 _extcall_prop = _prop;
 }
 /* connect user functions to hoc names */
 static IntFunc hoc_intfunc[] = {
 0,0
};
 static struct Member_func {
	char* _name; double (*_member)();} _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "I", _hoc_I,
 "M", _hoc_M,
 "firetime", _hoc_firetime,
 "newton1", _hoc_newton1,
 0, 0
};
#define I I_IntFire2
#define M M_IntFire2
#define firetime firetime_IntFire2
#define newton1 newton1_IntFire2
 extern double I();
 extern double M();
 extern double firetime();
 extern double newton1();
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "taus", "ms",
 "taum", "ms",
 0,0
};
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(), nrn_init(), nrn_state();
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 /* connect range variables in _p that hoc is supposed to know about */
 static char *_mechanism[] = {
 "6.2.0",
"IntFire2",
 "taus",
 "taum",
 "ib",
 0,
 "i",
 "m",
 0,
 0,
 0};
 
static void nrn_alloc(_prop)
	Prop *_prop;
{
	Prop *prop_ion, *need_memb();
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 8, _prop);
 	/*initialize range parameters*/
 	taus = 20;
 	taum = 10;
 	ib = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 8;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static _initlists();
 
#define _tqitem &(_ppvar[2]._pvoid)
 static _net_receive();
 typedef (*_Pfrv)();
 extern _Pfrv* pnt_receive;
 extern short* pnt_receive_size;
 _intfire2_reg_() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,0, 0, 0, nrn_init,
	 hoc_nrnpointerindex,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func,
	 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
  hoc_register_dparam_size(_mechtype, 3);
 add_nrn_artcell(_mechtype, 2);
 add_nrn_has_net_event(_mechtype);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_size[_mechtype] = 1;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 IntFire2 /home/cs/neurodroid/nrn/src/nrnoc/../.././nrn-hg/src/nrnoc/intfire2.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static _modl_cleanup(){ _match_recurse=1;}
 
double M ( _p, _ppvar, _thread, _nt ) double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt; {
   double _lM;
 double _lx , _lf ;
 _lf = taus / ( taus - taum ) ;
   _lx = ( i - ib ) * exp ( - ( t - t0 ) / taus ) ;
   _lM = ib + _lf * _lx + ( m - ( ib + ( i - ib ) * _lf ) ) * exp ( - ( t - t0 ) / taum ) ;
   
return _lM;
 }
 
static double _hoc_M(_vptr) void* _vptr; {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  M ( _p, _ppvar, _thread, _nt ) ;
 return(_r);
}
 
double I ( _p, _ppvar, _thread, _nt ) double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt; {
   double _lI;
 double _lx , _lf ;
 _lf = taus / ( taus - taum ) ;
   _lx = ( i - ib ) * exp ( - ( t - t0 ) / taus ) ;
   _lI = _lx + ib ;
   
return _lI;
 }
 
static double _hoc_I(_vptr) void* _vptr; {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  I ( _p, _ppvar, _thread, _nt ) ;
 return(_r);
}
 
static _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{  double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _thread = (Datum*)0; _nt = (_NrnThread*)_pnt->_vnt;   _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t;   if (_lflag == 1. ) {*(_tqitem) = 0;}
 {
   double _lx , _linew , _lf , _libf ;
 _lf = taus / ( taus - taum ) ;
   _lx = ( i - ib ) * exp ( - ( t - t0 ) / taus ) ;
   _linew = ib + _lx ;
   if ( _lflag  == 1.0 ) {
     net_event ( _pnt, t ) ;
     m = 0.0 ;
     _libf = ( _linew - ib ) * _lf ;
     artcell_net_send ( _tqitem, _args, _pnt, t +  firetime ( _threadargscomma_ ib , _libf , 0.0 ) , 1.0 ) ;
     }
   else {
     m = ib + _lf * _lx + ( m - ( ib + ( i - ib ) * _lf ) ) * exp ( - ( t - t0 ) / taum ) ;
     _linew = _linew + _args[0] ;
     if ( m >= 1.0 ) {
       artcell_net_move ( _tqitem, _pnt, t ) ;
       }
     else {
       _libf = ( _linew - ib ) * _lf ;
       artcell_net_move ( _tqitem, _pnt, firetime ( _threadargscomma_ ib , _libf , m ) + t ) ;
       }
     }
   t0 = t ;
   i = _linew ;
   } }
 
double firetime ( _p, _ppvar, _thread, _nt, _la , _lb , _lc ) double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt; 
	double _la , _lb , _lc ;
 {
   double _lfiretime;
 double _lr , _lcab , _lx , _lm , _lf ;
 _lr = taum / taus ;
   if ( _la <= 1.0  && _la + _lb <= 1.0 ) {
     _lfiretime = 1e9 ;
     }
   else if ( _la > 1.0  && _lb <= 0.0 ) {
     _lcab = _lc - _la - _lb ;
     _lm = _lr * _lb + _lcab ;
     if ( _lm >= 0.0 ) {
       _lfiretime = - taus * log ( newton1 ( _threadargscomma_ _la , _lcab , _lb , 1.0 / _lr , 0.0 ) ) ;
       }
     else {
       _lx = ( 1.0 - _lc + _lm ) / _lm ;
       if ( _lx <= 0.0 ) {
         _lfiretime = - taus * log ( newton1 ( _threadargscomma_ _la , _lcab , _lb , 1.0 / _lr , 0.0 ) ) ;
         }
       else {
         _lfiretime = - taum * log ( newton1 ( _threadargscomma_ _la , _lb , _lcab , _lr , _lx ) ) ;
         }
       }
     }
   else {
     _lcab = _lc - _la - _lb ;
     _lx = pow( ( - _lcab / ( _lr * _lb ) ) , ( 1.0 / ( _lr - 1.0 ) ) ) ;
     _lf = _la + _lb * pow( _lx , _lr ) + _lcab * _lx ;
     if ( _lx >= 1.0  || _lf <= 1.0 ) {
       _lfiretime = 1e9 ;
       }
     else {
       _lm = _lr * _lb + _lcab ;
       _lx = ( 1.0 - _lc + _lm ) / _lm ;
       _lfiretime = - taum * log ( newton1 ( _threadargscomma_ _la , _lb , _lcab , _lr , _lx ) ) ;
       }
     }
   
return _lfiretime;
 }
 
static double _hoc_firetime(_vptr) void* _vptr; {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  firetime ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) ) ;
 return(_r);
}
 
double newton1 ( _p, _ppvar, _thread, _nt, _la , _lb , _lc , _lr , _lx ) double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt; 
	double _la , _lb , _lc , _lr , _lx ;
 {
   double _lnewton1;
 double _ldx , _lf , _ldf , _liter , _lxm ;
 _ldx = 1.0 ;
   _lf = 0.0 ;
   _liter = 0.0 ;
   while ( fabs ( _ldx ) > 1e-6  || fabs ( _lf - 1.0 ) > 1e-6 ) {
     _lf = _la + _lb * pow( _lx , _lr ) + _lc * _lx ;
     _ldf = _lr * _lb * pow( _lx , ( _lr - 1.0 ) ) + _lc ;
     _ldx = ( 1.0 - _lf ) / _ldf ;
     _lx = _lx + _ldx ;
     if ( _lx <= 0.0 ) {
       _lx = 1e-4 ;
       }
     else if ( _lx > 1.0 ) {
       _lx = 1.0 ;
       }
     _liter = _liter + 1.0 ;
     if ( _liter  == 6.0  && _lr < 1.0 ) {
       _lxm = pow( ( - _lc / ( _lr * _lb ) ) , ( 1.0 / ( _lr - 1.0 ) ) ) ;
       }
     if ( _liter > 5.0 ) {
       }
     if ( _liter > 10.0 ) {
       printf ( "Intfire2 iter %g x=%g f=%g df=%g dx=%g a=%g b=%g c=%g r=%g\n" , _liter , _lx , _lf , _ldf , _ldx , _la , _lb , _lc , _lr ) ;
       _lf = 1.0 ;
       _ldx = 0.0 ;
       }
     }
   _lnewton1 = _lx ;
   
return _lnewton1;
 }
 
static double _hoc_newton1(_vptr) void* _vptr; {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  newton1 ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) , *getarg(5) ) ;
 return(_r);
}

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
 {
   i = ib ;
   m = 0.0 ;
   if ( taus <= taum ) {
     taus = taum + .1 ;
     }
   t0 = t ;
   artcell_net_send ( _tqitem, (double*)0, _ppvar[1]._pvoid, t +  firetime ( _threadargscomma_ ib , 0.0 , 0.0 ) , 1.0 ) ;
   }

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _tsav = -1e20;
 initmodel(_p, _ppvar, _thread, _nt);
}}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
 double _break, _save;
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
 _break = t + .5*dt; _save = t;
 v=_v;
{
}}

}

static terminal(){}

static _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}
