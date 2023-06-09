package com.sportslight.schedule.dao;

import java.util.List;


import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import com.sportslight.dto.ScheduleDTO;

@Mapper
@Repository
public interface ScheduleDAO {

	public List<ScheduleDTO> selectedScheduleList(@Param("leagueName")String leagueName);
	
	public List<ScheduleDTO> recentScheduleList(@Param("leagueName")String leagueName);
	
}//end class
