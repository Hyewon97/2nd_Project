package com.sportslight.mymy.dao;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import com.sportslight.dto.MemberFavorDTO;
import com.sportslight.dto.NoticeDTO;
import com.sportslight.dto.TeamDTO;
import com.sportslight.dto.VideoDTO;
import com.sportslight.dto.FavoriteDTO;
import com.sportslight.dto.HeartDTO;
import com.sportslight.dto.LeagueDTO;

@Mapper
@Repository
public interface MymyDAO {
	
	// 선호 설정 부분 ---------------------------------------
	
	// 팀 / 리그 정보 가져오기
	public List<LeagueDTO> getLeague();
	public List<TeamDTO> getTeam();
	
	// 선호 팀 / 리그 가져오기
	public MemberFavorDTO getFavor(int memberNum);
	
	// 선호 팀 수정
	public void updateFavorTeam(MemberFavorDTO mfDTO);
	
	// 좋아요/즐겨찾기 부분 ----------------------------------
	
	// 좋아요 동영상 가져오기
	public List<HeartDTO> getHeartVideo(int memberNum);
	
	// 좋아요 기반 추천 동영상 가져오기
	public VideoDTO getHeartRecommend(int videoNum);
	
	// 즐겨찾기 동영상 가져오기
	public List<FavoriteDTO> getFavoriteVideo(int memberNum);
	
	// 공지사항 부분 ----------------------------------------
	
	// 공지사항 리스트 가져오기
	public List<NoticeDTO> getNoticeList();
	
	// 공지사항 세부 보기
	public NoticeDTO getNoticeView(int noticeNUm);
	

}
